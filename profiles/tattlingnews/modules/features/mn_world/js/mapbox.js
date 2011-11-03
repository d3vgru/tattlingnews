Drupal.openlayers.layer = Drupal.openlayers.layer || {};

OpenLayers.Layer.MapBox = OpenLayers.Class(OpenLayers.Layer.TMS, {
    /*
     * Do not remove the MapBox or OpenLayers attribution from this code,
     * doing so is in violation of the terms of both licenses.
     */
    initialize: function (name, options) {
        var newArguments, // Arguments which will be automatically
                          // sent to the Layer.TMS constructor
            urls; // Multiple server URLs with the same contents 
                  // but distributed for performance
        mapbox_logo = "<a class='mapbox-branding' href='http://mapbox.com'></a> | <a href='http://mapbox.com/tos'>Terms of Service</a>";
        options = OpenLayers.Util.extend({
            attribution: mapbox_logo,
            maxExtent: new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34),
            maxResolution: 156543.0339,
            units: "m",
            type: "png",
            projection: "EPSG:900913",
            isBaseLayer: true,
            numZoomLevels: 19,
            displayOutsideMaxExtent: true,
            wrapDateLine: true
        }, options);
        urls = [
            "http://a.tile.mapbox.com/",
            "http://b.tile.mapbox.com/",
            "http://c.tile.mapbox.com/",
            "http://c.tile.mapbox.com/"
        ];
        newArguments = [name, urls, options];
        OpenLayers.Layer.TMS.prototype.initialize.apply(this, newArguments);
    },
    CLASS_NAME: "OpenLayers.Layer.MapBox"
});


Drupal.openlayers.layer.MapBox = function (name, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, options.name);
  if (options.options.maxExtent !== undefined) {
    options.options.maxExtent = new OpenLayers.Bounds.fromArray(options.options.maxExtent);
  }
  if (options.options.type === undefined){
    options.options.type = "png";
  }
  var layer = new OpenLayers.Layer.MapBox(name, options.options);
  layer.styleMap = styleMap;
  return layer;
}
