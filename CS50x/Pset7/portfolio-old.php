<div>
    <p>
    Marshal du hög <?=$username?>. Your current balance is <?=$cash?>.
    </p>
    	<?php
// 			print("Hello, ". $cash[0]["username"] .". Your current balance is " . sprintf("%.2f",$cash[0]["cash"]).".");
		?>
    <?php foreach ($positions as $position): ?>
        <tr>
            <td><?= number_format($position["symbol"], 2) ?></td>
            <td><?= number_format($position["price"], 2) ?></td>
            <td><?= number_format($position["shares"], 2) ?></td>
            <td><?= number_format($position["worth"], 2) ?></td>
        </tr>
    <?php endforeach ?>
    <!-- referenced: https://github.com/iman89/cs50/blob/3de547a9a88e0019446de10c52e72771d039106b/pset7/templates/portfolio.php
                 et: https://github.com/JonasHans/CS50-pset7/blob/master/pset7/templates/portfolio.php -->
</div>
