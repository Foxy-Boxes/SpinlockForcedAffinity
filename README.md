# SpinlockForcedAffinity

This is a performance test, that aims to compare spinlock performance under no constraint and under a set affinity (forcing two threads to work on the same core).
In my computer threads with set affinity perform 100x worse than the unconstrained counterpart.
