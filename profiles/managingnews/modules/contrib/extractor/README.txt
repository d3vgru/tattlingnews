$Id: README.txt,v 1.2 2010/03/01 16:31:36 rsoden Exp $

EXTRACTOR
=========

Simple term extraction API.

Usage
=====

With Feeds module:

- Install module
- Edit a feeds configuration, pick either "Common syndication parser with term
  extraction" or "SimplePie parser with term extraction".
- Go to "Mapping" settings of the processor and pick "Extracted term names" or
  "Extracted term tids" from the source drop down and map it to any target that
  handles arrays.

As API:

$terms = extractor_extract($text);

Yahoo Placemaker
================

The default tagging library in use is "Simple Extractor" which is a simple
look up algorithm based on a terms in a taxonomy vocabulary. Alternatively, the
Yahoo Placemaker API can be used as tagging library.

To use Yahoo Placemaker with Feeds module, click on the settings form of the
term extraction parser and select "Yahoo Placemaker" as extraction library. Then
supply an API key and if a different language than English should be used for
terms, specify the language code.

To use Yahoo Placemaker on the API level, call:

$terms = extractor_extract($text, 'placemaker', array('placemaker_key' => '<MYPMKEY>'));

or:

$terms = extractor_extract($text, 'placemaker', array('placemaker_key' => '<MYPMKEY>'), 'language' => 'fr');