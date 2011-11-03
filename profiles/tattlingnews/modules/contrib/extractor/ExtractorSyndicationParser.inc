<?php
// $Id: ExtractorSyndicationParser.inc,v 1.3 2010/09/08 03:04:08 alexb Exp $

require_once 'extractor.feeds.inc';

/**
 * Extend common syndication parser and add term extraction.
 */
class ExtractorSyndicationParser extends FeedsSyndicationParser {

  /**
   * Add additional mapping sources.
   */
  public function getMappingSources() {
    return parent::getMappingSources() + extractor_feeds_get_mapping_sources();
  }

  /**
   * If extracted_terms or extracted_tids was selected, extract terms and attach
   * them to item.
   */
  public function getSourceElement(FeedsImportBatch $batch, $element_key) {
    if ($result = extractor_feeds_get_source_element($batch->currentItem(), $element_key, $this->config)) {
      return $result;
    }
    return parent::getSourceElement($batch, $element_key);
  }

  /**
   * Config Form Defaults
   */
  public function configDefaults() {
    return extractor_feeds_defaults();
  }

  /**
   * Config Form
   */
  public function configForm(&$form_state) {
    return extractor_feeds_form($this->config);
  }
}