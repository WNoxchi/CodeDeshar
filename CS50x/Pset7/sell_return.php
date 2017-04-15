<!-- Wayne H Nixalo - 26-Dec-2016 22:40 -->
<p>
    <?=$sharesold?> share/s of '<?=$symbol?>' sold for $<?=number_format($price * $sharesold,2)?> at $<?=number_format($price,2)?> per share.
</p>
<p>
    Your account balance is: $<?=number_format($cash,2)?>. '<?=$symbol?>' shares remaining: <?=$shares?>.
</p>
