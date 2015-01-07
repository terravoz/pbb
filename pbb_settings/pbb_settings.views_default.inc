<?php
/**
 * @file
 * pbb_settings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pbb_settings_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_of_ideas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ideas collected';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ideas collected';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_audio' => 'field_audio',
    'body' => 'body',
    'field_episode_date' => 'field_episode_date',
    'view_node' => 'view_node',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_audio' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_episode_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Caller id */
  $handler->display->display_options['fields']['field_caller_id']['id'] = 'field_caller_id';
  $handler->display->display_options['fields']['field_caller_id']['table'] = 'field_data_field_caller_id';
  $handler->display->display_options['fields']['field_caller_id']['field'] = 'field_caller_id';
  $handler->display->display_options['fields']['field_caller_id']['label'] = 'Submitted by';
  $handler->display->display_options['fields']['field_caller_id']['type'] = 'text_plain';
  /* Field: Content: Idea category */
  $handler->display->display_options['fields']['field_idea_category']['id'] = 'field_idea_category';
  $handler->display->display_options['fields']['field_idea_category']['table'] = 'field_data_field_idea_category';
  $handler->display->display_options['fields']['field_idea_category']['field'] = 'field_idea_category';
  $handler->display->display_options['fields']['field_idea_category']['label'] = 'Category';
  /* Field: Content: Idea type */
  $handler->display->display_options['fields']['field_idea_type']['id'] = 'field_idea_type';
  $handler->display->display_options['fields']['field_idea_type']['table'] = 'field_data_field_idea_type';
  $handler->display->display_options['fields']['field_idea_type']['field'] = 'field_idea_type';
  /* Field: Content: Idea description */
  $handler->display->display_options['fields']['field_idea_description']['id'] = 'field_idea_description';
  $handler->display->display_options['fields']['field_idea_description']['table'] = 'field_data_field_idea_description';
  $handler->display->display_options['fields']['field_idea_description']['field'] = 'field_idea_description';
  $handler->display->display_options['fields']['field_idea_description']['label'] = '';
  $handler->display->display_options['fields']['field_idea_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_idea_description']['element_label_colon'] = FALSE;
  /* Field: Content: Idea location */
  $handler->display->display_options['fields']['field_idea_location']['id'] = 'field_idea_location';
  $handler->display->display_options['fields']['field_idea_location']['table'] = 'field_data_field_idea_location';
  $handler->display->display_options['fields']['field_idea_location']['field'] = 'field_idea_location';
  $handler->display->display_options['fields']['field_idea_location']['label'] = '';
  $handler->display->display_options['fields']['field_idea_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_idea_location']['element_label_colon'] = FALSE;
  /* Field: Content: Idea description audio */
  $handler->display->display_options['fields']['field_idea_description_audio']['id'] = 'field_idea_description_audio';
  $handler->display->display_options['fields']['field_idea_description_audio']['table'] = 'field_data_field_idea_description_audio';
  $handler->display->display_options['fields']['field_idea_description_audio']['field'] = 'field_idea_description_audio';
  $handler->display->display_options['fields']['field_idea_description_audio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_idea_description_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_idea_description_audio']['type'] = 'audiofield_nodownload';
  /* Field: Content: Idea location audio */
  $handler->display->display_options['fields']['field_idea_location_audio']['id'] = 'field_idea_location_audio';
  $handler->display->display_options['fields']['field_idea_location_audio']['table'] = 'field_data_field_idea_location_audio';
  $handler->display->display_options['fields']['field_idea_location_audio']['field'] = 'field_idea_location_audio';
  $handler->display->display_options['fields']['field_idea_location_audio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_idea_location_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_idea_location_audio']['type'] = 'audiofield_nodownload';
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = 'Location';
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_idea_type';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'Voice';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[field_idea_location_audio]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_idea_location]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = 'Description';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_idea_type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Voice';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_idea_description_audio]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_idea_description]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ideas' => 'ideas',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'ideas-collected';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Ideas collected';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['list_of_ideas'] = array(
    t('Master'),
    t('Ideas collected'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Date submitted'),
    t('Submitted by'),
    t('Category'),
    t('Idea type'),
    t('Idea description audio'),
    t('Idea location audio'),
    t('Location'),
    t('Description'),
    t('View'),
    t('Edit'),
    t('Delete'),
    t('Page'),
  );
  $export['list_of_ideas'] = $view;

  return $export;
}
