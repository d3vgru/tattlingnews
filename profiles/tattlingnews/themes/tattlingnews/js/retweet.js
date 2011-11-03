/*
 * Easy Retweet Button
 * http://ejohn.org/blog/retweet/
 *   by John Resig (ejohn.org)
 *
 * Licensed under the MIT License:
 * http://www.opensource.org/licenses/mit-license.php
 */

(function(){

window.RetweetJS = {
	// Your Bit.ly Username
	bitly_user: "retweetjs",

	// Your Bit.ly API Key
	// Found here: http://bit.ly/account
	bitly_key: "R_6287c92ecaf9efc6f39e4f33bdbf80b1",

	// The text to replace the links with
	link_text: "Tweet",

	// What # to show (Use "clicks" for # of clicks or "none" for nothing)
	count_type: "none",

	// Tweet Prefix text
	// "RT @jeresig " would result in: "RT @jeresig Link Title http://bit.ly/asdf"
	prefix: "",
	
	watermark: " (from @tattlerapp)",

	// Style information
	styling: ""
};

//////////////// No Need to Configure Below Here ////////////////

var loadCount = 1;

// Asynchronously load the Bit.ly JavaScript API
// If it hasn't been loaded already
if ( typeof BitlyClient === "undefined" ) {
	var head = document.getElementsByTagName("head")[0] ||
		document.documentElement;
	var script = document.createElement("script");
	script.src = "http://bit.ly/javascript-api.js?version=latest&login=" +
		RetweetJS.bitly_user + "&apiKey=" + RetweetJS.bitly_key;
	script.charSet = "utf-8";
	head.appendChild( script );

	var check = setInterval(function(){
		if ( typeof BitlyCB !== "undefined" ) {
			clearInterval( check );
			head.removeChild( script );
			loaded();
		}
	}, 10);

	loadCount = 0;
}

if ( document.addEventListener ) {
	document.addEventListener("DOMContentLoaded", loaded, false);

} else if ( window.attachEvent ) {
	window.attachEvent("onload", loaded);
}

function loaded(){
	// Need to wait for doc ready and js ready
	if ( ++loadCount < 2 ) {
		return;
	}

	var elems = [], urlElem = {}, hashURL = {};

	BitlyCB.shortenResponse = function(data) {
		for ( var url in data.results ) {
			var hash = data.results[url].userHash;
			hashURL[hash] = url;

			var elems = urlElem[ url ];

			for ( var i = 0; i < elems.length; i++ ) {
				elems[i].href += hash;
        elems[i].href += RetweetJS.watermark				
			}

			if ( RetweetJS.count_type === "clicks" ) {
				BitlyClient.stats(hash, 'BitlyCB.statsResponse');
			}
		}
	};

	BitlyCB.statsResponse = function(data) {
		var clicks = data.results.clicks, hash = data.results.userHash;
		var url = hashURL[ hash ], elems = urlElem[ url ];

		if ( clicks > 0 ) {
			for ( var i = 0; i < elems.length; i++ ) {
				var strong = document.createElement("strong");
				strong.appendChild( document.createTextNode( clicks + " " ) );
				elems[i].insertBefore(strong, elems[i].firstChild);

				if ( /(^|\s)vert(\s|$)/.test( elems[i].className ) ) {
					elems[i].firstChild.className = elems[i].lastChild.className = "vert";
				}
			}
		}

		hashURL[ hash ] = urlElem[ url ] = null;
	};

	if ( document.getElementsByClassName ) {
		elems = document.getElementsByClassName("retweet");
	} else {
		var tmp = document.getElementsByTagName("a");
		for ( var i = 0; i < tmp.length; i++ ) {
			if ( /(^|\s)retweet(\s|$)/.test( tmp[i].className ) ) {
				elems.push( tmp[i] );
			}
		}
	}

	for ( var i = 0; i < elems.length; i++ ) {
		var elem = elems[i];

		var origText = elem.title,
			  href = elem.href;

		//elem.innerHTML = "<span>" + RetweetJS.link_text + "</span>";
		elem.title = "";
		elem.href = "http://twitter.com/home?status=" +
			encodeURIComponent(RetweetJS.prefix + origText + " http://bit.ly/");

		if ( urlElem[ href ] ) {
			urlElem[ href ].push( elem );
		} else {
			urlElem[ href ] = [ elem ];
			BitlyClient.shorten(href, 'BitlyCB.shortenResponse');
		}
		
	}

}

})();
