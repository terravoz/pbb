<?php
// $Id$
/**
 * @file
 * Audio Blog VoIP Scripts and helper functions
 */

/**
 * Implementation of hook_voipscript_get_script_names()
 */
function pbb_voipscript_get_script_names() {
  $script_names[] = 'pbb_welcome_script';
  return $script_names;
}

/**
 * Implementation of hook_voipscript_load_script()
 */
function pbb_voipscript_load_script($script_name, $options = NULL) {

  $script = NULL;
  switch ($script_name) {
    default:
      break;
    case 'pbb_welcome_script':
      $script = new VoipScript('pbb_welcome_script');
      $options['voice'] = 'pbb-english';
      $voice = $options['voice'];
      voipvoice_set_current_voice($voice);

      $script->addSay(v("Hi, thank you for calling Youth Lead the Change!"));

      //@todo: implement check if this is inbound or outbound call
      $options['signup_number'] = '%caller_number';
      $script->addGosub('pbb_main_menu', $options);
      break;
    case 'pbb_main_menu':
      $script = new VoipScript('pbb_main_menu');
      $script->addLabel('options_menu');
      $voice = $options['voice'];
      voipvoice_set_current_voice($voice);

      $signup_number = VoipCall::NormalizeNumber($options['signup_number']);
      watchdog('debug', 'signup number ' . $signup_number);
      $phone_number = VoipNumber::getVoipNumbersByNumber($signup_number, 'node', 'phone_number');

      if($phone_number) {
        //We should recognize an existing caller id and offer the option to unsubscribe right from the main menu.
        $sms_subscribe_msg = v('To unsubscribe from our contact list for text message updates, press 2.');
      }
      else {
        $sms_subscribe_msg = v('To enroll in our contact list for text message updates, press 2.');
      }

      $p_options_menu[] = v("Main menu. To learn more about Youth Lead the Change and Participatory Budgeting, press 1. ");
      $p_options_menu[] = $sms_subscribe_msg;
      $p_options_menu[] = v("To contribute your project idea to improve the city of Boston, press 3.
      To be redirected to our Boston Youth Lead the Change headquarters, press 0.
      To repeat this message, press the star key.");

      $input_options = array(
        '1' => 'get_information',
        '2' => 'sms_subscription',
        '3' => 'propose_idea',
        '0' => 'redirect',
        '*' => 'repeat',
        '#' => 'invalid_option',
        'i' => 'invalid_option',
        't' => 'invalid_option'
      );
      $p_invalid_msg = v('Oops! That option is invalid. ');
      $script->addRunIvrMenu($p_options_menu, $input_options, $p_invalid_msg);
      $script->addGoto('%ivr_option_selected');

      /*$script->addLabel('audio_announcements');
      $script->addGosub('audio_announcements_play_blogs_script', $options);
      $script->addGoto('options_menu');
*/

      $script->addLabel('propose_idea');
      $script->addGosub('propose_idea_script', $options);
      $script->addGoto('options_menu');

      $script->addLabel('sms_subscription');
      $options['signup_number'] = '%caller_number';
      $script->addGosub('pbb_sms_subscription_menu', $options);
      $script->addGoto('options_menu');

      $script->addLabel('get_information');
      //@todo: implement subscribe/unsubscribe here too
      if($phone_number) {
        //We should recognize an existing caller id and offer the option to unsubscribe right from the main menu.
        $sms_subscribe_msg = v('To unsubscribe from our contact list for text message updates, press 2.');
      }
      else {
        $sms_subscribe_msg = v('If you would like to receive text message updates about Youth Lead the Change, press 2.');
      }
      $prompt = array();
      $prompt[] = v('Welcome to Youth Lead the Change, the only youth-led participatory budgeting process in the country!
Youth Lead the Change-Participatory Budgeting Boston  is an innovative democratic process that gives young people the power to decide how to spend one million dollars in capital funds to improve their city.
In participatory budgeting, residents brainstorm ideas for community improvement projects, develop these ideas into full proposals, and then vote on a ballot for which projects will be funded and implemented. Anyone ages 12 to 25 that lives in Boston will be eligible to vote in May! ');
      $prompt[] = $sms_subscribe_msg;
      $prompt[] = v('To go back to the main menu, press the pound key.');
      $script->addGetInput($prompt, 1);
      $script->addGotoIf('sms_subscription', "^%input_digits == '2'");
      $script->addGoto('options_menu');

      $script->addLabel('redirect');
      $script->addSay(v('Your call will now be redirected to Boston HQ. '));
      //$script->addDial('+16466993989');
      $script->addGoto('hang_up');

      $script->addLabel('repeat');
      $script->addGoto('options_menu');

      $script->addLabel('invalid_option');
      $script->addGoto('hang_up');

      $script->addLabel('hang_up');
      $script->addHangup();
      break;

    case 'pbb_sms_subscription_menu':
      $script = new VoipScript('pbb_sms_subscription_menu');
      $voice = $options['voice'];
      voipvoice_set_current_voice($voice);

      $signup_number = VoipCall::NormalizeNumber($options['signup_number']);
      watchdog('debug', 'signup number ' . $signup_number);
      $phone_number = VoipNumber::getVoipNumbersByNumber($signup_number, 'node', 'phone_number');
      watchdog('debug', 'voipnumber  ' . print_r($phone_number, TRUE));
      if ($phone_number) {
        //Number already exists unsubscribe it
        node_delete($phone_number[0]->getEid());
        $text = variable_get('sms_actions_sms_unsubscribe', 'You\'ve unsubscribed from the Callblast App and should not receive further messages. Should you choose to subscribe again, text any letter to this number.');
        $voice_message = v('Your number has been successfully removed from our text message reminders. ');
      }
      else {
        //New number, subscribe it
        $node->type = 'phone_number';
        $node->title = $signup_number;
        $node->language = 'und';
        $node->status = 1;
        $node->field_opt_in['und'][0]['value'] = 1; //verify
        $node->field_phone_number['und'][0]['vnid'] = $signup_number;
        $language = 'en';
        $node->field_language['und'][0]['value'] = $language;
        // create the node
        node_save($node);

        //send welcome message
        $text = variable_get('sms_actions_sms_welcome', 'Welcome to Participatory Budgeting Boston.');
        $voice_message = v('Great! Your number has been successfully added to our text message reminders.
      You will now receive reminders to contribute ideas and join Youth Lead the Change events!');
      }

      $script->addSendText($text, $signup_number);
      $script->addLabel('message');
      $script->addSay($voice_message);
      $script->addGosub('pbb_main_menu', $options);
      //$script->addReturn();
      break;

    case 'propose_idea_script':
      $script = new VoipScript('propose_idea_script');
      $voice = $options['voice'];
      voipvoice_set_current_voice($voice);

      $script->addLabel('start');
      $script->addSay(v('Great! Remember, ideas have to be for physical projects to improve the city of Boston.
      Ideas should not be for programs and services. '));
      $script->addLabel('options_menu');
      $prompt = v("If your idea is for Schools and Education projects, press 1.
  If it is for Streets and Transportation and Community Safety projects, press 2.
  If it is for Arts and Culture projects, press 3.
  If it is Parks and Environment projects press 4.
  If it is for Community Centers projects press 5.
  If it is for Libraries projects press 6.
  To hear these options again, press the star key. To go back to the main menu, press the pound key.");
      $timeout = 5;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($prompt, $num_digits, $end_key, $timeout);

      $script->addGotoIf('confirm_category', "^_pbb_validate_idea_category(%input_digits)");
      $script->addGotoIf('options_menu', "^%input_digits == '*'");
      $script->addGotoIf('go_back', "^%input_digits == '#'");

      $script->addSay(v('Oops! That option is invalid. '));
      $script->addGoto('options_menu');

      $script->addLabel('confirm_category');
      $script->addSet('category_name', "^_pbb_get_category_name(%input_digits)");

      $prompt = array();
      $prompt[] = v("You selected");
      $prompt[] = v("%category_name");
      $prompt[] = v("To accept this category, press 1. To choose a different category, press 2.");
      $timeout = 5;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($prompt, $num_digits, $end_key, $timeout);
      $script->addGotoIf('setcategory', "^%input_digits == '1'");
      $script->addGotoIf('options_menu', "^%input_digits == '2'");
      $script->addSay(v('Oops! That option is invalid. '));
      $script->addGoto('confirm_category');

      $script->addLabel('setcategory');
      $script->addSet('idea_category', '%input_digits');

      //Record location
      $script->addLabel('start_recording_location');

      $prompt = t("Now please name the neighborhood and the streets or intersection for which your idea applies. When you are finished, press #. ");
      $timeout = 5;
      $end_key = '#';
      $max_length = 200;
      $format = 'mp3';

      $script->addRecord($prompt, $timeout, $end_key, $max_length, $format);

      $script->addLabel('confirm_location');
      $prompt = array();
      $prompt[] = v("You said");
      $prompt[] = new VoipPrompt("%recording_public_url");
      $prompt[] = v("To confirm this location, press 1. To record it once again, press 2.");
      $timeout = 5;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($prompt, $num_digits, $end_key, $timeout);
      $script->addGotoIf('set_idea_location', "^%input_digits == '1'");
      $script->addGotoIf('start_recording_location', "^%input_digits == '2'");

      $script->addSay(v('Oops! That option is invalid. '));
      $script->addGoto('confirm_location');

      $script->addLabel('set_idea_location');
      $script->addSet('idea_location', '%recording_public_url');

      //Record idea
      $script->addLabel('start_recording_idea');
      $script->addLog('About to start recording (%voipscript_hangup_callback)');

      $prompt = t("Now please say describe your idea in up to 45 seconds. When you are finished, press #. ");
      $timeout = 5;
      $end_key = '#';
      $max_length = 45;
      $format = 'mp3';

      $script->addRecord($prompt, $timeout, $end_key, $max_length, $format);

      $script->addLabel('confirm_description');
      $prompt = v("To listen to your idea, press 1. To accept it, press, 2. To record it once again, press 3.");
      $timeout = 5;
      $end_key = '';
      $num_digits = 1;
      $script->addGetInput($prompt, $num_digits, $end_key, $timeout);
      $script->addGotoIf('listen_idea_description', "^%input_digits == '1'");
      $script->addGotoIf('set_idea_description', "^%input_digits == '2'");
      $script->addGotoIf('start_recording_idea', "^%input_digits == '3'");

      $script->addSay(v('Oops! That option is invalid. '));
      $script->addGoto('confirm_description');

      $script->addLabel('listen_idea_description');
      $script->addSay('%recording_public_url');
      $script->addGoto('confirm_description');

      $script->addLabel('set_idea_description');
      $script->addSet('idea_recording', '%recording_public_url');

      $script->addSet('callback_result',
        '^_pbb_save_idea(%idea_category, %idea_location, %idea_recording, %caller_number, %source)');

      $script->addLabel('idea_submitted');
      $script->addSay(v('Thanks for submitting your idea to Youth Lead the Change!.'));

      $script->addLabel('go_back');
      $script->addReturn();
      break;
    case 'pbb_sms_collect_idea':
      $script = new VoipScript('pbb_sms_collect_idea');
      $script->addLabel('start');
      $script->addSendText("Please choose idea category:
      1=Schools & Education
2=Streets & Transportation & Community Safety
3=Arts & Culture
4=Parks & Environment
5=Community Centers
6=Libraries");
      $script->addHangup('resume');

      $script->addLabel('category');
      $script->addGotoIf('setcategory', "^_pbb_validate_idea_category(%inbound_text_contents)");
      $script->addSendText('Oops! That option is invalid. ');
      $script->addHangup('resume');

      $script->addLabel('setcategory');
      $script->addSet('idea_category', '%inbound_text_contents');

      //location
      $script->addLabel('location');
      $script->addSendText("Now please name the neighborhood and the streets or intersection for which your idea applies.");
      $script->addHangup('resume');

      $script->addSet('idea_location', '%inbound_text_contents');

      //idea description
      $script->addLabel('idea_description');

      $script->addSendText("Now please describe your idea. ");
      $script->addHangup('resume');

      $script->addSet('idea_recording', '%inbound_text_contents');

      $script->addSet('callback_result',
        '^_pbb_save_idea_sms(%idea_category, %idea_location, %idea_recording, %caller_number, %source)');

      $script->addLabel('end call');
      $script->addSendText('Your idea is saved. Thank you.');
      $script->addHangup();
      break;
  }

  return $script;
}

function _pbb_validate_idea_category($category_selected) {
  $category_selected = (int) $category_selected;
  if ($category_selected >= 1 && $category_selected <= 6) {
    watchdog('debug', 'returning true');
    return TRUE;
  }
  else {
    watchdog('debug', 'returning false');
    return FALSE;
  }
}

function _pbb_get_category_name($category_selected) {
  $category_selected = (int) $category_selected;
  $categories = _pbb_categories();
  return $categories[$category_selected];
}