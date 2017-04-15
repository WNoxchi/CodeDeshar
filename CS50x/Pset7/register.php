<!-- WHNixalo 23-Dec-2016 15:43 www.portfolium.com/Borz-->
<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["username"])) {
            apologize("Username required");
        }
        else if (empty($_POST["password"])) {
            apologize("Password requried");
        }
        else if ($_POST["password"] != $_POST["confirmation"]) {
            apologize("Passwords do not match");
        }
        else {
            // insert registry -- raise error if username exists
            $rows = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 9001.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            if ($rows == 0) {
                apologize("Username already exists");
            }
            // auto login after register
            else {
                // get id
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                // store id in session
                $_SESSION["id"];
                // redirect to index.php
                redirect("index.php");
            }
        }
    }

    // can find out what id assigned to inserted user (if successful):
    // $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
    // $id = $rows[0]["id"];

?>
