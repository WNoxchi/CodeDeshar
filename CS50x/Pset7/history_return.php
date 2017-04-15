<p align="center">
    Transaction History
</p>
<table class="table table-striped">
    <thead>
        <tr>
            <th>DATE</th>
            <th>ACTION</th>
            <th>STOCK</th>
            <th>SHARES</th>
        </tr>
    </thead>
    <tbody align="left">
        <?php foreach ($transactions as $transaction): ?>
            <tr>
                <td><?= $transaction["date"] ?></td>
                <td><?= $transaction["action"] ?></td>
                <td><?= $transaction["symbol"] ?></td>
                <td><?= $transaction["shares"] ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>
</table>
