// UNDERSCORE.JS   -   CS50x   -   WNx     -   03-Jan-2017 17:56
// http://underscorejs.org/

// UTILITY: template    -   http://underscorejs.org/#template
_.template(templateString, [settings])

// Compiles JavaScript templates into functions that can be evaluated for rendering.

var compiled = _.template("hello: <%= name %>");
compiled({name: 'moe'});
=> "hello: moe"

var template = _.template("<b><%- value %></b>");
template({value: '<script>'});
=> "<b>&lt;script&gt;</b>"

// Can also use print from w/n JavaScript code instead of <%= ... %>
var compiled = _.template("<% print('Hello ' + epithet); %>");
compiled({epithet: "stooge"});
=> "Hello stooge"

// Can change Underscore's template to use different symbols to set off interpolated code
_.templateSettings = {
    interpolate: /\{(.+?)\}\}/g
};

var template = _.template("Hello {{ name }}!");
template({name: "Mustache"});
=> "Hello Mustache!"

// By default, template places the values from your data in the local scope via
// the with statement. You can specify a single variable name with the variable setting
// to speed template render time
_.template("Using 'with': <%= data.answer %>", {variable: 'data'})({answer: 'no'});
=> "Using 'with': no"

// the source property available on the compiled template function for easy precompilation
<script>
    JST.project = <%= _.template(jstText).source %>


</script>

// COLLECTION FUNCTIONS (ARRAYS OR OBJECTS)

    // each
    _.each(list, iteratee, [context])   // Alias: forEach

    _.each([1, 2, 3], alert);
    => alerts each number in tern...
    _.each({cxa: 1, shi: 2, kxo: 3}, alert);
    => alerts each number value in turn...

    // map
    _.map(list, iteratee, [context])    // Alias: collect

    _.map([1, 2, 3], function(num){ return num * 3; });
    => [3, 6, 9]
    _.map({cxa: 1, shi: 2, kxo: 3}, function(num, key){ return num * 3; });
    => [3, 6, 9]
    _.map([[1, 2], [3, 4]], _.first);
    => [1, 3]

    // reduce
    _.reduce(list, iteratee, [memo], [context]) // Aliases: inject, foldl

    var sum = _.reduce([1, 2, 3], function(memo, num){ return memo + num; }, 0);
    => 6

    // reduceRight
    _.reduceRight(list, iteratee, [memo], [context])    // Alias: foldr

    var list = [[0,1], [2,3], [4,5]];
    var flat = _.reduceRight(list, function(a, b) { return a.concat(b); }, []);
    => [4,5,2,3,0,1]

    // find
    _.find(list, predicate, [context])  // Alias: detect

    var even = _.find([1,2,3,4,5,6], function(num){ return num % 2 == 0; });
    => 2

    // filter
    _.filter(list, predicate, [context])    // Alias: select

    var evens = _.filter([1,2,3,4,5,6], function(num){ return num % 2 == 0; });
    => [2, 4, 6]

    // where
    _.where(list, properties)

    _.where(listOfPlays, {author: "Shakespeare", year: 1611});
    => [{title: "Cymbeline", author: "Shakespeare", year: 1611},
        {title: "The Tempest", author: "Shakespeare", year: 1611}]

    // findWhere
    _.findWhere(list, properties)

    _.findWhere(publicServicePulitzers, {newsroom: "The New York Times"});
    => {year: 1918, newsroom: "The New York Times",
      reason: "For its public service in publishing in full so many official reports, documents, and speaches by European statesmen relating to the progress and conduct of the war."}

    // reject
    _.reject(list, predicate, [context])

    var odds = _.reject([1,2,3,4,5,6], function(num){ return num % 2 == 0; });

    // every
    _.every(list, [predicate], [context])   // Alias: all

    _.every([2,4,5], function(num) { return num % 2 == 0; });
    => false
