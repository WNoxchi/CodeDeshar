<p>
    Marsha Doghiyl <?=$username?>. Your current accounnt balance is $<?=number_format($cash,2)?>.
</p>

<table class="table table-striped">

    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>

    <tbody align="left">
        <?php foreach ($positions as $position): ?>
            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td>$<?= $position["price"] ?></td>
                <td>$<?= number_format($position["price"]*$position["shares"],2) ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>

</table>
