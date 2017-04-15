<form action="change_password.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="username" placeholder="Username" type="text"/>
        </div>
        <div class="form-group">
            <input autocomplete="off" class="form-control" name="old_password" placeholder="Old Password" type="password"/>
        </div>
        <div class="form-group">
            <input autocomplete="off" class="form-control" name="new_password" placeholder="New Password" type="password"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Change Password
            </button>
        </div>
    </fieldset>
</form>

<div>
    or <a href="login.php">return to login</a>
</div>
