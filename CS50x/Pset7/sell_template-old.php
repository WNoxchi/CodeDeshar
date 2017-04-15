<form action="sell.php" method="post">
    <fieldset>
        <!-- should this be a form-group instead? -->
        <!-- <div class="control-group">  -->
        <div class="form-group">
            <input autofocus class="form-control" name="code" placeholder="Stock symbol" type="text"/>
            <!-- <input autocomplete="off" name="code" placeholder="Stock symbol" type="text"/> -->
            <input name="amount" placeholder="No. of Shares" type="text"/>
        </div>
        <!-- <div class="control-group"> -->
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                Sell
            </button>
        </div>
    </fieldset>
</form>
