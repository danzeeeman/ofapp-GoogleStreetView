##ofapp-GoogleStreetView

This is a simple openFrameworks app that shows you how to grab high res tiles from Google Street View.  


So you run an HTTP GET to this address:	"http://cbk0.google.com/cbk?output=xml&ll=33.748302,-84.397306" with the ll=LONG,LAT in this case we are looking at [Magic City](http://bit.ly/KRZPeV) an infamous strip club in Atlanta Georgia.  

It returns something that looks like this: 


				<panorama>
					<data_properties image_width="13312" image_height="6656" tile_width="512" tile_height="512" image_date="2008-03" pano_id="sLaiF6Jex7mJmNol7tdOoA" num_zoom_levels="3" lat="51.495078" lng="-0.147004" original_lat="51.495073" original_lng="-0.146987" best_view_direction_deg="113.528">
					<copyright>© 2012 Google</copyright>
					<text>Eccleston Place</text>
					<region>London, England</region>
					<country>United Kingdom</country>
					<data_flag>1</data_flag>
					</data_properties>
					<projection_properties projection_type="spherical" pano_yaw_deg="204.15" tilt_yaw_deg="-17.52" tilt_pitch_deg="0.75"/>
					<annotation_properties>
					<link yaw_deg="25.37" pano_id="t_mnKSugTLrQTEnJplXQ3A" road_argb="0x80ffffff" scene="0">
					<link_text>Ebury Street / Eccleston Place</link_text>
					</link>
					<link yaw_deg="205.51" pano_id="x8-xIY7hWYkqrVqoePGdJQ" road_argb="0x80ffffff" scene="0">
					<link_text>Eccleston Place</link_text>
					</link>
				</annotation_properties>
				</panorama>

You are looking for the pano_id="sLaiF6Jex7mJmNol7tdOoA"

You then issue a HTTP GET to this address: "http://cbk0.google.com/cbk?output=tile&panoid=PANOID"&zoom=ZOOMLEVEL&x=XX&y=YY" 

	where

		PANOID = pano_id from the panorama XML

	The zoom level

		zoom = 0 || 1 || 2 || 3 || 4 || 5 

		if zoom = 0, X=0 and Y=0

		if zoom = 1, X = (0-1) and Y = 0

		if zoom = 2, X = (0-3) and Y = (0-1)

		if zoom = 3, X = (0-5) and Y = (0-2)

		if zoom = 4, X = (0-12) and Y = (0-6)

		if zoom = 5 X = (0-25) and Y = (0-12)


Currently this App is set to use zoom level 3. 


For more information on the subject you can look at [Jamie Thompson's](http://jamiethompson.co.uk/web/2010/05/15/google-streetview-static-api/) page on the GoogleMaps Static API. 