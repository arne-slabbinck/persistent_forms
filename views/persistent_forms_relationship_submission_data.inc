<?php
/**
 * @file
 * Views' relationship handlers.
 */

class persistent_forms_handler_relationship_submission_data extends views_handler_relationship  {

  function option_definition() {
    $options = parent::option_definition();
    $options['persistent_forms_form_id'] = array('default' => NULL);
    $options['persistent_forms_field'] = array('default' => NULL);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    //form_load_include($form_state, 'inc', 'persistent_forms', 'views/persistent_forms.views');

    $form_id = (int) $this->options['persistent_forms_form_id'];
    $field = (int) $this->options['persistent_forms_field'];

    $form['persistent_forms_form_id'] = array(
      '#type' => 'select',
      '#title' => t('Drupal $form_id'),
      '#options' => array(),
    );

    $persistent_forms = _persistent_forms_get_persistent_forms();
    $options = array_combine($persistent_forms, $persistent_forms);
    $form['persistent_forms_form_id']['#options'] = $options;

    // Helper function provides persistent_forms_nid and persistent_forms_cid options.
    /*_persistent_forms_views_options_form($form, $form_state, $nid, $cid);*/
  }

  /*function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    _persistent_forms_views_options_validate($form, $form_state);
  }*/

/*  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
    _persistent_forms_views_options_submit($form, $form_state);
  }*/

  /**
   * Called to implement a relationship in a query.
   *
   * It respects the given component ids, provided via options form.
   */
  function query() {
    /*$this->definition['extra'][] = array(
      'table' => NULL,
      'field' => "%alias.nid",
      'value' => $this->options['persistent_forms_nid'],
    );
    $this->definition['extra'][] = array(
      'table' => NULL,
      'field' => "%alias.cid",
      'value' => $this->options['persistent_forms_cid'],
    );*/

    // The rest of building the join is performed by the parent.
    parent::query();
  }
}
