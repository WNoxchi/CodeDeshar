<?php
    // NOTE: reference: https://github.com/iman89/cs50/blob/3de547a9a88e0019446de10c52e72771d039106b/pset7/html/login.php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("login_form.php", ["title" => "Log In"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }

        // query database for user
        $rows = CS50::query("SELECT * FROM users WHERE username = ?", $_POST["username"]);

        // if we found user, check password
        if (count($rows) == 1)
        {
            // first (and only) row
            $row = $rows[0];

            // compare hash of user's input against hash that's in database
            if (password_verify($_POST["password"], $row["hash"]))
            {
                // remember that user's now logged in by storing user's ID in session
                $_SESSION["id"] = $row["id"];
                // UPDATE 26-Dec-2016 19:43: by storing username & cash we can use those indices later in index & portfolio
                $_SESSION["username"] = $row["username"];
                $_SESSION["cash"] = $row["cash"];

                // redirect to portfolio
                redirect("/");
            }
        }

        // else apologize
        apologize("Invalid username and/or password.");
    }
    else
    {
        // else just render form
        render("login_form.php", ["title" => "Log In"]);
    }

?>
