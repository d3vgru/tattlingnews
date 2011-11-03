<?php
// $Id: plus1.api.php,v 1.1.2.1 2011/01/13 16:14:32 nancyw Exp $

/**
 * @file
 * Hooks provided by the Plus1 module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Control whether voting is allowed.
 *
 * Modules may implement this hook if they want to have a say in whether or not
 * a given user is allowed to vote on a given node.
 *
 * The administrative account (user ID #1) does not bypass this access check.
 *
 * Note that not all modules will want to influence access. If your module
 * does not want to actively grant or block access, return PLUS1_ACCESS_IGNORE
 * or simply return nothing. Blindly returning FALSE will break other Plus1
 * access modules.
 *
 * @param $nid
 *   The node id on which the vote is to be cast.
 * @param $op
 *   The operation to be performed. Possible values:
 *   - "create"
 *   - "view"
 * @param $account
 *   A user object representing the user for who is about to cast the vote.
 *
 * @return
 *   PLUS1_ACCESS_ALLOW if voting is to be allowed;
 *   PLUS1_ACCESS_DENY if voting is to be denied;
 *   PLUS1_ACCESS_IGNORE to not affect voting at all.
 */
function hook_plus1_access($node, $op, $account) {
  // Only show widget on selected node types
  if (!in_array($node->type, variable_get('plus1_nodetypes', array()))) {
    return PLUS1_ACCESS_DENY;
  }

  // If the node voting is disabled, deny.
  if ($node->plus1_disable_vote) {
    return PLUS1_ACCESS_DENY;
  }

  // If the user has already voted - don't let another vote be registered
  if ($op == 'vote' && plus1_get_votes($node->nid, $account->uid)) {
    return PLUS1_ACCESS_DENY;
  }

  return PLUS1_ACCESS_IGNORE;
}
