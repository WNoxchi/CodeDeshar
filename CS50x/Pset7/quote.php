<!-- WNx - 24-Dec-2016 15:39
    checked against iman89: https://github.com/iman89/cs50/tree/master/pset7/templates
    looking up stock's latest price using lookup in helpers.php:
    $stock = lookup($_POST["symbol"]);                          -->

<?php
    // config
    require("../includes/config.php");

    // diplay form
    // GET is clicking a link or a redirect
    // if ($_SERVER["REQUEST_METHOD"] == "GET") {
    //     render("quote_form.php", ["code" => "Lookup Quote"]);
    // }
    // POST is submitting a form
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // check if form submitted empty:
        if (empty($_POST["code"])) {
            apologize("Quote field empty");
        }
        // use Yahoo query to retrieve stock quote
        $stock = lookup($_POST["code"]);
        // check valid
        if ($stock == false) {
            apologize("Stock Code not found");
        }
        // display stock quote
        else {
            render("quote_return_template.php", ["title" => "Quote", "symbol" => $stock["symbol"], "name" =>  $stock["name"], "price" => $stock["price"]]);
        }
    }
    // if form not submitted yet, display form to get stock symbol
    else {
        render("quote_form.php", ["code" => "Lookup Quote"]);
    }
?>
