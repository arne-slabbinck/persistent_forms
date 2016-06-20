<?php

/**
 * @file
 * Views handler to display data value of a submission field.
 */

/**
 * Field handler to show submission data.
 *
 * @ingroup views_field_handlers
 */
class persistent_forms_handler_field_submission_data extends views_handler_field_custom {

  function option_definition() {
    $options = parent::option_definition();
    $options['persistent_forms_form_id'] = array('default' => NULL);
    $options['persistent_forms_field'] = array('default' => NULL);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    form_load_include($form_state, 'inc', 'persistent_forms', 'persistent_forms.form');

    $persistent_forms_form_id = $this->options['persistent_forms_form_id'];  
    $persistent_forms_field = $this->options['persistent_forms_field'];

    _persistent_forms_views_field_handler_form($form, $form_state, $persistent_forms_form_id, $persistent_forms_field);

  }

  function options_validate(&$form, &$form_state) {
    parent::options_validate($form, $form_state);
    _persistent_forms_views_field_handler_form_validate($form, $form_state);
  }

  public function pre_query() {
    parent::pre_query();
    $alias = $this->query->add_table('persistent_forms_submission_data');
    $this->field_alias = $this->query->add_field($alias, 'value');
    $this->query->add_where(0, "{$alias}.field", $this->options['persistent_forms_field']);
  }

  function render($row) {
    return $row->{$this->field_alias};
  }

}
