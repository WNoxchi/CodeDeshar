<?php
    // WNx - 26-Dec-2016 22:34

    require("../includes/config.php");

    if ($_SERVER("REQUEST_METHOD") == "POST") {
        // make sure form submission valid:
        if (empty($_POST["code"]) || empty($_POST["amount"])) {
            apologize("Submission field missing";
            // should I redirect or re-render to re-submit?
            // render("sell_template.php", ["code" => "Stock Symbol", "amount" => "No. of Shares");
        }
        // lookup stock on Yahoo & get user id too
        else {
            $stock = lookup($_POST["code"]);
            $id = $_SESSION["id"];
        }
        if ($stock == false) {
            apologize("Stock Code not found");
            // render("sell_template.php", ["code" => "Stock Symbol", "amount" => "No. of Shares");
        }
        // query amount of users shares:
        $shares = CS50::query("SELECT shares FROM portfolios WHERE id = $id AND symbol = '$stock'");      // can also use for symbol: ... symbol = ?", strtoupper($_POST["code"]);
        if (!$shares) {
            apologize("You don't own shares of this stock");
        } else {
            // if amount valid get transaction information
            $value = lookup("$stock");
            $shares = $shares[0]["shares"];
            $price = $value["price"];
            $profit = $shares * $price;

            // update user portfolio by deleting sold shares
            CS50::query("DELETE FROM portfolios WHERE id = $id AND symbol = '$stock'");
            CS50::query("UPDATE users SET cash + $profit WHERE id = $id");
            // CS50::query("INSERT INTO history (id, symbol, status, shares, price) VALUES($id, '$stock', 'SELL', $shares, $price)");
            // display result of sale
            render("sell_update_form.php", ["title" => "Stock Sale", "value" => $value, "profit" => $profit]);
            // render("sell_update_form.php", [
            //                 "title"     => "Stock Sale",
            //                 "symbol"    => $stock["symbol"],
            //                 "name"      => $stock["name"],
            //                 "price"     => $stock["price"]
            //                 //TODO: total cash
            //                 //TODO: amt shares
            //                 //TODO: remaining shares
            //             ]);
        }
    }
    else {
        // display form for sell operation
        render("sell_template.php", ["code" => "Stock Symbol", "amount" => "No. of Shares"]);
    }

?>
