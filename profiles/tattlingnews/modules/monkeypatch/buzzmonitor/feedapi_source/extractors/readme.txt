Extractors are strategy implementations for retrieving original
mention URL when mentions come from obfuscating services like
Digg.

See existing extractors to get an idea about implementing a new one.
Two functions you have to implement are: extract() and getWeight().
getWeight() allows queue-ing different extractors in the right
sequence.