Retrievers are strategy implementations for retrieving original Blog's 
URL off of a mention's URL. Usually you need to run an extractor first
to make sure you are working with the original mention's URL not
something pre-processed by Digg or alike.

Retrievers are hooked-up via:

MentionSourceExtractor->retrieverFactory() in feedapi_source.class.php 