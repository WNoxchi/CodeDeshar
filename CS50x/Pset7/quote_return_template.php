<!-- WNx 24-Dec-2016 16:38 -->

<!-- at minimum, display quote -->

<!-- ensure stock is valid -->
    <!-- else: display error -->

<!-- print("Price: " . $s["price"]); -->
<!-- use number_format to frmt to 2-4 dec places -->

<p>
    <!-- The stock value of <?php //$stock["name"] ?> (<?php //$stock["symbol"] ?>) is <?php //$stock["price"] ?>. <- apparently this is done as below: -->
    The stock value of <?=$name?> (<?=$symbol?>) is $<?=number_format($price, 2)?>.
</p>
