# Performance
We measured the performance of the tictactoe game at various search depths and found that as expected, greater search depths lead to longer runtime. As the board becomes less empty, the max search depth decreases, leading to faster runtime.

The runtime is also impacted by alpha-beta pruning. We can drastically decrease runtime after utilizing alpha-beta pruning.

|Tictactoe Runtime Performance With Alpha-beta Pruning | Tictactoe Runtime Performance Without Alpha-beta Pruning|
|--|--|
|![](data/pics/tictactoe-with-pruning.png)|![](data/pics/tictactoe-no-pruning.png)|

A comparison between pruning vs. no pruning is made for an initially empty tic-tac-toe board. We can see that especially when the max search depth is very large, alpha-beta pruning reduces the search time by more than 1/2.

![](data/pics/tictactoe-comparison.png)