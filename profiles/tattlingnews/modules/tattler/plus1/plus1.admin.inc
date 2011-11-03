<?php
// $Id: plus1.admin.inc,v 1.1.2.2 2011/01/13 18:14:07 nancyw Exp $

/**
 * @file
 * A simple +1 voting widget module.
 * Settings file.
 */

/**
 * Menu callback to configure module settings.
 */
function plus1_settings() {
  $form = array();
  $noyes = array(t('No'), t('Yes'));

  // Add vertical tabs display if available.
  $form['#pre_render'] = array('vertical_tabs_form_pre_render');

  $form['plus1_general_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -10,
    );

  $form['plus1_general_fieldset']['plus1_nodetypes'] = array(
    '#type' => 'checkboxes',
    '#options' => node_get_types('names'),
    '#default_value' => variable_get('plus1_nodetypes', array()),
    '#description' => t('Select all content types to which a +1 voting widget can be added.'),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_general_fieldset']['plus1_vote_on_own'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Allow author to vote on own content'),
    '#default_value' => variable_get('plus1_vote_on_own', 1),
    '#description' => t('Do you wish to allow a post\'s author to vote on his/her own content?.'),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_general_fieldset']['plus1_show_link'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Show a summary link in the content'),
    '#default_value' => variable_get('plus1_show_link', 0),
    '#description' => t('The link shows how many votes a post has received.'),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_general_fieldset']['plus1_allow_disable'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Allow disabling votes on an individual post'),
    '#default_value' => variable_get('plus1_allow_disable', 0),
    '#description' => t('This will allow the author or editor to disable voting on a single post. The list of disabled posts should not be excessively long or it may impact performance.'),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_general_fieldset']['plus1_delete_nodes'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Delete votes when post is deleted'),
    '#default_value' => variable_get('plus1_delete_nodes', 1),
    '#description' => t('This will clean up the vote counting tables in the database if the post is deleted.'),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_general_fieldset']['plus1_delete_users'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Delete votes when user is deleted'),
    '#default_value' => variable_get('plus1_delete_users', 1),
    '#description' => t('This will clean up the vote counting tables in the database if the user account is deleted.'),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display settings'),
    '#description' => t('You may select none, one, or both options. There is also a block available, if you want the widget in a sidebar.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -5,
    );

  $form['plus1_display']['plus1_in_teaser'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Add a +1 voting widget to the node in teaser view.'),
    '#default_value' => variable_get('plus1_in_teaser', 0),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_display']['plus1_in_full_view'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Add a +1 voting widget to the node in full view.'),
    '#default_value' => variable_get('plus1_in_full_view', 1),
    '#attributes' => array('class' => 'container-inline'),
    );

  $form['plus1_text'] = array(
    '#type' => 'fieldset',
    '#title' => t('Text settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 0,
    );

  $form['plus1_text']['plus1_vote'] = array(
    '#type' => 'textfield',
    '#title' => t('Suggest voting'),
    '#default_value' => variable_get('plus1_vote', 'Vote'),
    '#description' => t('Feedback provided to voter when he (she) has not voted. Enter, for example, <em>Digg</em>, <em>Vote</em>, or <em>Like</em>.'),
    );

  $form['plus1_text']['plus1_you_voted'] = array(
    '#type' => 'textfield',
    '#title' => t('User already voted'),
    '#default_value' => variable_get('plus1_you_voted', 'You voted'),
    '#description' => t('Feedback provided to voter when he (she) has already voted. Enter, for example, <em>Dugg</em>, <em>You voted</em>, or <em>Voted</em>.'),
    );

  $form['plus1_text']['plus1_login_to_vote'] = array(
    '#type' => 'textfield',
    '#title' => t('Suggest logging in'),
    '#default_value' => variable_get('plus1_login_to_vote', 'Log in to vote'),
    '#description' => t('Feedback provided to voter when he (she) is not logged in. Enter, for example, <em>Log in to vote</em>.'),
    );

  $form['plus1_text']['plus1_author_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Author text'),
    '#default_value' => variable_get('plus1_author_text', 'Your content'),
    '#description' => t('Feedback provided to voter when he/she is the author and is allowed to vote on it. Leave this blank to disable the notification. Enter, for example, <em>&lt;small>My post&lt;/small></em>.'),
    );

  $form['plus1_text']['plus1_after_vote_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Author text'),
    '#default_value' => variable_get('plus1_after_vote_text', 'Thank you for your vote.'),
    '#description' => t('Feedback provided to voter after the vote. Leave ths blank to disable the notification. Enter, for example, <em>We\'re glad you like this post</em>.'),
    );

  $form['plus1_text']['link'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link text'),
    '#description' => t('These are used to build the summary link (if requested). Include "!score" (without quotes) where you wish to show the count.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    );

  $form['plus1_text']['link']['plus1_link_singular'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text - singular'),
    '#default_value' => variable_get('plus1_link_singular', t('!score Vote')),
    );

  $form['plus1_text']['link']['plus1_link_plural'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text - plural'),
    '#default_value' => variable_get('plus1_link_plural', t('!score Votes')),
    );

  $form['plus1_theming'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theming settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 5,
    );

  $form['plus1_theming']['plus1_widget_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Widget class'),
    '#default_value' => variable_get('plus1_widget_class', 'plus1-widget'),
    );

  $form['plus1_theming']['plus1_link_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Link class'),
    '#default_value' => variable_get('plus1_link_class', 'plus1-link'),
    );

  $form['plus1_theming']['plus1_msg_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Message class'),
    '#default_value' => variable_get('plus1_msg_class', 'plus1-msg'),
    );

  $form['plus1_theming']['plus1_score_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Score class'),
    '#default_value' => variable_get('plus1_score_class', 'plus1-score'),
    );

  $form['plus1_theming']['plus1_link_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Link count class'),
    '#default_value' => variable_get('plus1_link_count', 'plus1-link-count'),
    );

  $form['plus1_weight'] = array(
    '#type' => 'fieldset',
    '#title' => t('Weight settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 5,
    );

  $form['plus1_weight']['plus1_weight'] = array(
    '#type' => 'weight',
    '#delta' => 20,
    '#title' => t('Weight of voting widget'),
    '#default_value' => variable_get('plus1_weight', 20),
    '#description' => t('The higher the weight the lower in the node the widget will be added. You can usually place it at the top with -10.'),
    );

  $form['array_filter'] = array('#type' => 'hidden');
  $form['buttons'] = array('#weight' => 99);

  return system_settings_form($form);
}
