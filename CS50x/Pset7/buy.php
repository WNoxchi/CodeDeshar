<?php
    // WNX - 27-Dec-2016 17:33
    // config
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // check fields empty
        if (empty($_POST["symbol"]) || empty($_POST["shares"])) {
            apologize("Invalid Buy: Missing Submission Field");
        }
        // check number of shares is valid integer
        if (preg_match("/^\d+$/", $_POST["shares"]) == false) {
            apologize("Invalid Buy: Number of Shares must be positive integer");
        }
        else {
            // get stock info
            $stock = lookup($_POST["symbol"]);
            // check user can afford purchase
            $userfunds = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            $userfunds = $userfunds[0]["cash"];     // probly inefficient, but I don't know a more direct way yet
            if ($userfunds < $stock["price"] * $_POST["shares"]) {
                apologize("Invalid Transaction: Insufficient Funds");
            }
            else {
                // if user doesnt have stock, add it to portfolio -- else udpate shares
                // if (!$user_portfolio = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"])) {     // <-- obsolete
                // }
                CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?)
                            ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
                                $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
                // deduct purchase price from user's account
                CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $stock["price"] * $_POST["shares"], $_SESSION["id"]);

                // update transaction history
                CS50::query("INSERT INTO history (user_id, symbol, shares, action, date) VALUES(?,?,?,'BUY', Now())",
                                $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);

                $totalshares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
                $totalshares = $totalshares[0]["shares"];
                // display result of transaction
                render("buy_return.php", ["title" => "Buy", "symbol" => $_POST["symbol"], "shares" => $_POST["shares"], "price" => $stock["price"], "totalshares" => $totalshares]);
            }
        }
    }
    // else render form to submit:
    else {
        render("buy_form.php", ["title" => "Buy"]);
    }

 ?>
