<?php
// CS50 php emailer manual: http://cs50.stackexchange.com/questions/11101/how-do-i-send-an-email-with-php
//                          https://manual.cs50.net/mail/
    // WNx - 27-Dec-2016 22:37
    // config
    // require("../includes/config.php");   // <-- this will check if user logged in and redirect to login page if not

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_password_form.php", ["title" => "Change Password"]);
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // make sure all fields filled:
        if (empty($_POST["username"]) || empty($_POST["old_password"]) || empty($_POST["new_password"])) {
            apologize("Missing submission field");
        }
        // get user from database
        $user = CS50::query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
        // if user found: proceed
        if (count($user) == 1) {
            // focus on user's database row
            $user = $user[0];
            // make sure old password is correct
            if (!password_verify($_POST["old_password"], $user["hash"])) {
                apologize("Incorrect old password");
            }
            // correct?: update password with new
            else {
                // update password --- if fail report error
                if (CS50::query("UPDATE users SET hash = ? WHERE username = ?", crypt($_POST["new_password"]), $_POST["username"]) == false) {
                    apologize("Internal Error. Password not updated.");
                } else {
                    render("change_password_return.php", ["title" => "Password Changed"]);
                }
            }
        }
    }
    else {
        render("change_password_form.php", ["title" => "Change Password"]);
    }
 ?>
