<?php
    // Wayne H Nixalo - 27-Dec-2016 20:29 - 21:44
    // config
    require("../includes/config.php");

    $rows = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    $transactions = [];
    foreach ($rows as $row) {
        $transactions[] = [
            "date" => $row["date"],
            "action" => $row["action"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"]
        ];
    }

    render("history_return.php", ["title" => "History", "transactions" => $transactions]);

 ?>
