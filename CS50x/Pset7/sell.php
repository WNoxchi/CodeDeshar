<?php
    // WNx - 27-Dec-2016 14:45
    // config
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // check fields empty
        if (empty($_POST["symbol"]) || empty($_POST["shares"])) {
            apologize("Transaction Field Empty");
        }
        else {
            // retrieve stock info
            $stock = lookup($_POST["symbol"]);
            if (!$stock) {
                apologize("Stock Not Found");
            }
            // check user has shares of stock
            $id = $_SESSION["id"];
            $portfolio_to_sell = CS50::query("SELECT * FROM portfolios WHERE user_id = $id AND symbol = ?", $_POST["symbol"]);
            // do I have to now: $stock_to_sell = $stock_to_sell[0]; -- looks like it
            $portfolio_to_sell = $portfolio_to_sell[0];

            // if stock doesn't exist in portfolio
            if (!$portfolio_to_sell) {
                apologize("Invalid Sale: You do not own shares of this stock");
            }
            // if not enough shares of stock in portfolio
            if ($portfolio_to_sell["shares"] < $_POST["shares"]) {
                apologize("Invalid Sale: You do not own the number of shares you wish to sell");
            }
            // otherwise OK: SELL
            else {
                // if sell all shares then DELETE portfolio row
                if ($portfolio_to_sell["shares"] == $_POST["shares"]) {
                    CS50::query("DELETE FROM portfolios WHERE user_id = $id AND symbol = ?", $_POST["symbol"]);
                }
                // otherwise subtract number sold
                else {
                    CS50::query("UPDATE portfolios SET shares = ? WHERE user_id = $id AND symbol = ?", $portfolio_to_sell["shares"] - $_POST["shares"], $_POST["symbol"]);
                }
                // udpate account balance
                CS50::query("UPDATE users SET cash = cash + ? WHERE id = $id", $_POST["shares"]*$stock["price"]);

                // update transaction history
                CS50::query("INSERT INTO history (user_id, symbol, shares, action, date) VALUES(?,?,?,'SELL', Now())",
                                $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);

                $sharesold = $_POST["shares"];
                // $price = $stock["price"];
                $symbol = $_POST["symbol"];
                $cash = CS50::query("SELECT cash FROM users WHERE id = $id");
                $cash = $cash[0]["cash"];   // get the "cash" element of the array
                // $cash = $_SESSION["cash"]; <-- this is incorrect: will only display balance at time of login
                $shares = $portfolio_to_sell["shares"] - $_POST["shares"];
                // display transaction result
                render("sell_return.php", ["title" => "Sell", "sharesold" => $sharesold, "symbol" => $symbol, "price" => $stock["price"], "cash" => $cash, "shares" => $shares]);
            }
        }
    }
    // if submission not made render sale window
    else {
        render("sell_form.php", ["title" => "Sell"]);
    }

    // help:       http://andrewke.org/problem-set-7/
    //             https://github.com/iman89/cs50/blob/3de547a9a88e0019446de10c52e72771d039106b/pset7/html/sell.php
    //             https://github.com/JonasHans/CS50-pset7/blob/master/pset7/public/sell.php

 ?>
