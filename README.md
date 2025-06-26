# Task#1. Orderbook

After launching the program, you need to enter buyers and sellers according to the following principle. 
The first number is the buyer/seller indicator. 
The second number is how many UAH we want to sell or buy. 
The third number is the price for 1 UAH in USD 
Ànd the last number is "sell" if you want to create a seller or "buy" if you want to create a buyer. Then you press "enter" and enter a new buyer or seller.

Enter data separated by a space, not a comma.

When you finish the program, you need to write “exit”. 
After that, the program will start creating purchases and sales between buyers and sellers.

You should receive the following message “Matching orders...” and then all transactions will be displayed. 

For example:

Enter the following buyers and sellers:
> 1 100 27 buy
> 2 50 25 sell
> 3 30 28 buy
> 4 70 26 sell

After we enter:
> exit
The program will display the following results:
Matching orders...
Trade executed:
BalanceChange{user_id: 2, value: -1350, currency: USD
BalanceChange{user_id: 2, value: 50, currency: UAH
BalanceChange{user_id: 1, value: 1350, currency: USD
BalanceChange{user_id: 1, value: -50, currency: UAH
Trade executed:
BalanceChange{user_id: 4, value: -840, currency: USD
BalanceChange{user_id: 4, value: 30, currency: UAH
BalanceChange{user_id: 3, value: 840, currency: USD
BalanceChange{user_id: 3, value: -30, currency: UAH

We have 2 transactions. The first one is between buyer 2 and seller 1. 
Buyer 2 bought 50 UAH from seller 1 for 1350 USD.

The second transaction was between seller 3 and buyer 4. 
Buyer 4 bought 30 UAH from seller 3 for 840 USD.