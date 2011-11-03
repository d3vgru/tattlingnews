$Id: README.txt,v 1.1 2008/05/27 19:54:22 milosh Exp $

==================================================================================
Basic usage
==================================================================================

Enable the feedapi_itemfilter module and those filters that you would like to use
in your site. The filters' settings will appear under the feed settings.

For more specific use of specific filter see the documentation of these filters.

You can enable/disable and modify filter for each feed. (Don't forget to enable the
filter that you want to use, as the filters are disabled by default and I have already
learned that it is easy to forget to turn them on... :) ).

You can access the filter settings on each feed page as well as under feed enabled
'content type' settings. If you modify the filter settings under 'content type' then
these settings will become the default settings for the new items of this content type.
So for the keyword filter --  if you would use the same keywords in different feeds
then it is good idea to first fill the keywords under 'content type' settings and then
create the feeds. In this way these keywords will be already available, when you create
new feed (and obviously you can modify them individually when you are creating feed).

Please note that item filtering will consume time. So it would be good idea to keep
the filters simple. If you use different filter types on top of each other, then try
to run less time consuming filters first. For example, if you would use both keyword
filter and regular expressions filter (to be released soon) together, then it is wise
to run keyword filter before regular expressions filter, as keyword filter is faster
and it already reduces feed->items, so regular expressions filter will run on lesser
items. On the same line -- if you will use timestamp filter (to be released soon) and
keyyword filter together, then it would be wise to run timestamp filter before keyword
filter.

==================================================================================
Writing new filters
==================================================================================

Filters are written as new Drupal modules, so they should have the same file structure
that all Drupal modules have.

You should implement two hooks in your filter:

1) hook_help() is used in order to let the filters be listed.

You can just copy the hook_help() code from feedapi_keyword_filter.module and
substitute t('Keyword filter') with the name of your filter.

2) hook_feedapi_itemfilter($op, &$feed, &$options) is used for defining the
settings page for your filter (under $op = 'settings') and for filtering
the items (under $op = 'process').

Don't forget to substitute the feed->items with your filtered item-set
at the end of function under 'process' switch.

The hook is used in the following manner:

/**
 * Implementation of hook_feedapi_itemfilter()
 *
 * @param string $op
 *    $op = 'settings' will modify FeedAPI item filter settings page. You can define
 *           the form for any filter-specific settings here.
 *    $op = 'process' will process the feed with your filter.
 * @param array &$feed
 *    This is feed array, which was returned from parsers. It is used under 'process' stage
 * @param array &$options
 *    Array of FeedAPI options. It includes the filter options that you required
 *           when the 'settings' page was altered.
 * @return  if $op = 'settings' then the form array for filter settings is returned
 *          if $op = 'process' then nothing is returned: it is expected that you
 *                    modified feed->items directly in your code (see line 116 below).
 */

See example usage of the hooks in feedapi_keyowrd_filter.module for further guidance.
