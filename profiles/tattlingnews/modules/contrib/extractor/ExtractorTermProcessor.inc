<?php
// $Id: ExtractorTermProcessor.inc,v 1.1 2010/09/09 23:11:23 alexb Exp $

/**
 * This processor makes every imported term a lookup term.
 */
class ExtractorTermProcessor extends FeedsTermProcessor {
  /**
   * Mark every imported term as lookup term.
   */
  public function map(FeedsImportBatch $batch, $target_item = NULL) {
    if (!$target_item) {
      $target_item = array();
    }
    $target_item['extractor_lookup'] = TRUE;
    return parent::map($batch, $target_item);
  }
}
