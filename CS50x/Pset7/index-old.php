<?php
    // WNx - 26-Dec-2016 18:23
    // referenced: https://github.com/JonasHans/CS50-pset7/blob/master/pset7/public/index.php
    //         et: https://github.com/iman89/cs50/blob/3de547a9a88e0019446de10c52e72771d039106b/pset7/html/index.php

    // configuration
    require("../includes/config.php");

    // first get all shares the user owns
    $rows = CS50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);   // NOTE: method from iman89: https://github.com/iman89/cs50/blob/3de547a9a88e0019446de10c52e72771d039106b/pset7/html/index.php
    // $rows = quert("SELECT symbol, shares, price FROM shares WHERE user_id = ?", $_SESSION["id"]); // NOTE: method from JonasHans: https://github.com/JonasHans/CS50-pset7/blob/master/pset7/public/index.php

    // position array stores all info abt user's shares
    $positions = [];
    // iterate/loop across all shares user owns
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name"      => $stock["name"],
                "price"     => number_format($stock["price"], 2),
                "shares"    => $row["shares"],
                "symbol"    => $row["symbol"],
                "worth"     => number_format($row["shares"] * $row["price"], 2)    // can also use: sprintf("%.2f, <amount>)
                // "worth"     => sprintf("%.2f", $row["shares"] * $row["price"])
            ];
        }
    }
    $cash = CS50::query("SELECT username, cash FROM users WHERE id = ?", $_SESSION["id"]);

    render("portfolio.php", [
                "positions" => $positions,
                "title"     => "Portfolio",
                "username"  => $_SESSION["username"],
                "cash"      => number_format($_SESSION["cash"], 2)
                // "username"  => $cash["username"],
                // "cash"      => $cash["cash"]
            ]);
    // render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "cash" => $cash]);

 ?>
