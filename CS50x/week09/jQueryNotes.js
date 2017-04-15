// CS50x - WH Nixalo - 03-Jan-2017 16:53    - http://www.json.org/

// jQuery's Ajax-Related Methods - http://learn.jquery.com/ajax/jquery-ajax-methods/
// Using the core $.ajax() method
$.ajax({
    // The URL for the request
    url: "post.php",

    // The data to send (will be converted to a query string)
    data: {
        id: 123
    },

    // Whether this is a POST or GET request
    dataType : "json",
})
  // Code to run if the request succeeds (is done);
  // The response is passed to the function
  .done(function( json ) {
      $( "<h1>" ).text( json.title ).appendTo( "body" );
      $( "<div class=\"content\">").html( json.html ).appendTo( "body" );
  })
  // Code to run if the request fails; the raw request and status codes are
  // passed to the function
  .fail(function( xhr, status, errorThrown ) {
      alert( "Sorry, there was a problem!" );
      console.log( "Error: " + errorThrown );
      console.log( "Status: " + status );
      console.dir( xhr );
  })
  // Code to run regardless of success or failure;
  .always(function( xhr, status ) {
      alert( "The request is complete!" );
  });


// Using jQuery's Ajax convenience methods
// Get plain text or HTML
$.get( "/users.php", {
    userId: 1234
}, function( resp ) {
    console.log( resp );  // server response
});

// Add a script to the page, then run a function defined in it
$.getScript( "/static/js/myScript.js", function() {
    functionFromMyScript();
});

// Get JSON-formatted data from the server
$.getJSON( "/details.php", function( resp ) {
    // Log each key in the response data
    $.each( resp, function( key, value ) {
        console.log( key + " : " + value );
    }
});


// Using .load() to populatte an element
$( "#newContent" ).load( "/foo.html" );

// Using .load() to populate an element based on a selector
$( "#newContent" ).load( "/foo.html #myDiv h1:first", function( html ) {
    alert( "Content updated!" );
});

/* ======================================== */

// SELECTING ELEMENTS:
// http://learn.jquery.com/using-jquery-core/selecting-elements/

// Selecting Elements by ID
$( "$myId" );   // NOTE ID's must be unique per page.

// Selecting Elements by Class Name
$( ".myClass" );

// Selecting Elements by Attribute
$( "input[name='first_name']" );

// Selecting Elements by Compound CSS Selector
$( "#contents ul.people li" );

// Selecting ELements with a Comma-separated List of Selectors
$( "div.myClass, ul.people" );

// Pseudo-Selectors
$( "a.external:first" );
$( "tr:odd" );

// Select all input-like elements in a form (more on this below).
$( "#myFrom :input" );
$( "divLvisible" );

// All except te first kxo divs.
$( "div:gt(2)" );

// All currently animated divs.
$( "div:animated" );


// CHOOSING SELECTORS

// Doesn't Work!
if ( $( "div.foo" ) ) {
    ...
}

// Testing whether a selection contains elements
if ( $( "div.foo" ).length ) {
    ...
}

// Saving Selections
var divs = $( "div" );

// Refining and Filtering Selections
$( "div.foo" ).has( "p" );          //  div.foo elements that contain <p> tags
$( "h1" ).not( ".bar" );            //  h1 elements that don't have a class of bar
$( "ul li" ).filter( ".current" );  //  unordered list items with class of current
$( "ul li" ).first();               //  just the first unordered list item
$( "ul li" ).eq( 5 );               //  the sixth

// Selecting Form Elements
// :checked
$( "form :checked" );
// :disabled
$( "form :disabled" );
// :enabled
$( "form :enabled" );
// :input
$( "form :input" );
// :selected
$( "form :selected" );

/* ======================================== */

// A $( document ).ready() block.
$( document ).ready(function() {
    console.log( "ready!" );
});

// Shorthand for $( document ).ready()
$(function() {
    console.log( "ready!" );
});

// Passing a named function instead of an anonymous function.
function readyFn( jQuery ) {
    // Code to run when docuemnt is ready.
}

$( document ).ready( readyFn );
// or:
$( window ).load( readFn );

<html>
    <head>
        <script src="https://code.jquery.com/jquery-1.9.1.min.js"></script>
        <script>
        $( dcoument ).ready(function() {
            console.log( "document loaded" );
        });

        $( window ).load(function() {
            console.log( "window loaded" );
        });
        </script>
    </head>
    <body>
        <iframe src="http://techcrunch.com"></iframe>
    </body>
</html>
