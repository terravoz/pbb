<?php
/**
 * @file
 * pbb_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function pbb_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__ideas';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_ideas';
  $strongarm->value = '0';
  $export['language_content_type_ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ideas';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_ideas';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ideas';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_ideas';
  $strongarm->value = '1';
  $export['node_preview_ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_ideas';
  $strongarm->value = 1;
  $export['node_submitted_ideas'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Participatory Budgeting Boston (+1 401-227-7882)';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_action_help';
  $strongarm->value = '?, h';
  $export['sms_actions_action_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_action_pbb_collect_idea';
  $strongarm->value = 'idea, i';
  $export['sms_actions_action_pbb_collect_idea'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_action_subscribe';
  $strongarm->value = 'subscribe, j';
  $export['sms_actions_action_subscribe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_action_unsubscribe';
  $strongarm->value = 's, u';
  $export['sms_actions_action_unsubscribe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_keywords';
  $strongarm->value = array(
    'IDEA' => 'pbb_sms_collect_idea',
    'I' => 'pbb_sms_collect_idea',
    'SUBSCRIBE' => 'sms_actions_action_subscribe',
    'J' => 'sms_actions_action_subscribe',
    'S' => 'sms_actions_action_unsubscribe',
    'U' => 'sms_actions_action_unsubscribe',
    '?' => 'sms_actions_action_help',
    'H' => 'sms_actions_action_help',
  );
  $export['sms_actions_keywords'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_opt_message';
  $strongarm->value = 'PBB would like to send you SMS reminders at this number. H for help. S to end. Msg&data rates may apply. Reply J to confirm today.';
  $export['sms_actions_opt_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_sms_duplicate';
  $strongarm->value = 'Number already registered.';
  $export['sms_actions_sms_duplicate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_sms_help';
  $strongarm->value = 'Welcome to Participatory Budgeting Boston! To JOIN text "J". To STOP receiving text messages, text "S". To add new idea, text "I". For HELP, text "H". Msg & data rates may apply.';
  $export['sms_actions_sms_help'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_sms_not_in_list';
  $strongarm->value = 'Number not in the list.';
  $export['sms_actions_sms_not_in_list'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_sms_unknown';
  $strongarm->value = 'Unknown command.';
  $export['sms_actions_sms_unknown'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_sms_unsubscribe';
  $strongarm->value = 'You\'ve unsubscribed from the Participatory Budgeting Boston and should not receive further messages. Should you choose to subscribe again, text any letter to this number.';
  $export['sms_actions_sms_unsubscribe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'sms_actions_sms_welcome';
  $strongarm->value = 'Welcome to Participatory Budgeting Boston.';
  $export['sms_actions_sms_welcome'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_cid_name';
  $strongarm->value = 'Participatory Budgeting Boston';
  $export['voipcall_cid_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_cid_number';
  $strongarm->value = '+14012277882';
  $export['voipcall_cid_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_default_session_time';
  $strongarm->value = '60';
  $export['voipcall_default_session_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_default_text_handler';
  $strongarm->value = '';
  $export['voipcall_default_text_handler'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_inbound_call_script_name';
  $strongarm->value = 'pbb_welcome_script';
  $export['voipcall_inbound_call_script_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_inbound_text_script_name';
  $strongarm->value = 'sms_actions_sms_handler_script';
  $export['voipcall_inbound_text_script_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voipcall_outbound_call_script_name';
  $strongarm->value = 'voipcall_default_outbound_call_script';
  $export['voipcall_outbound_call_script_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voip_default_server';
  $strongarm->value = 'twilio';
  $export['voip_default_server'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'voip_twilio_settings';
  $strongarm->value = array(
    'voiptwilio_account_sid' => 'AC6db4e788b04ccd21ad6c06eb72a4aecd',
    'voiptwilio_auth_token' => '266f1959b22ac77b360f03e31fd707ed',
    'form_build_id' => 'form-nBfeF4WGkogs_Yd1kl2O5UdNNFVkez_36AfxrM8HG4A',
  );
  $export['voip_twilio_settings'] = $strongarm;

  return $export;
}
