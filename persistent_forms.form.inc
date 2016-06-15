<?php

/**
 * 
 */
function _persistent_forms_views_field_handler_form(&$form, &$form_state, $persistent_forms_form_id = null, $persistent_forms_field = null) {
  $persistent_forms = _persistent_forms_get_persistent_forms();

	$form['persistent_forms_form_id'] = array(
    '#type' => 'select',
    '#title' => t('Form'),
    '#options' => array(
      '' => t('- Select -'),
    ),
    '#default_value' => $persistent_forms_form_id,
    '#ajax' => array(
      'path' => views_ui_build_form_url($form_state),
    ),
    '#submit' => array('views_ui_config_item_form_submit_temporary'),
    '#executes_submit_callback' => TRUE,
  );

  $form_ids = array_keys($persistent_forms);
  $form['persistent_forms_form_id']['#options'] += array_combine($form_ids, $form_ids);

  $form['persistent_forms_field'] = array(
    '#type' => 'select',
    '#title' => t('Field'),
    '#options' => array(
      '' => t('- Select -'),
    ),
    '#access' => !empty($persistent_forms_form_id),
  );

  if (!empty($persistent_forms[$persistent_forms_form_id])) {
    $fields = array_values($persistent_forms[$persistent_forms_form_id]);
    $form['persistent_forms_field']['#options'] += array_combine($fields, $fields);
  }

}

/**
 * 
 */
function _persistent_forms_views_field_handler_form_validate(&$form, &$form_state) {
  /*if (!empty($form_state['values']['options']['persistent_forms_form_id'])) {
    if (empty($form_state['values']['options']['persistent_forms_field'])) {
      form_set_error('persistent_forms_field', t('Field %field is required', array('%field' => 'Field')));
    }  
  }*/
}
