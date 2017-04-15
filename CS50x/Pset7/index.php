<?php
    // Wayne H. Nixalo - 27-Dec-2016 17:59
    // Problem Set 7: http://cdn.cs50.net/2016/x/psets/7/pset7/pset7.html#portfolio_2

    // config
    require("../includes/config.php");

    // get users portfolio
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);

    // build array to pass into view as a table
    $positions = [];
    foreach ($rows as $row) {
        // get the name of each stock
        $stock = lookup($row["symbol"]);
        // if the name is valid (found): add to array
        if ($stock !== false) {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }

    // get users total balance
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $cash = $cash[0]["cash"];

    // pass array of stock positions & total balance into view
    render("portfolio.php", ["title" => "Portfolio", "username" => $_SESSION["username"], "positions" => $positions, "cash" => $cash]);// "" => $w, "" => $v, "" => $t]);

 ?>
