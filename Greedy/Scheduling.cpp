/*
    PROBLEM:
    --------
    We are given N activities.

    Each activity has:
        start time
        end time

    We can attend an activity only if it does not overlap
    with the previously selected activity.

    Find the MAXIMUM NUMBER of non-overlapping activities.


    EXAMPLE:
    --------
    Activities:
        [1, 3]
        [2, 5]
        [4, 6]
        [6, 8]

    We can select:
        [1,3] -> [4,6] -> [6,8]

    Answer = 3


    GREEDY IDEA:
    ------------
    Sort all activities by their ENDING TIME.

    Why?

    If we choose the activity that finishes earliest,
    we leave the maximum amount of time for future activities.

    So:

        Sort by end time
        ↓
        Take the activity if:
            start >= lastEnd
        ↓
        Update lastEnd


    IMPORTANT:
    ----------
    We are maximizing the NUMBER of activities,
    NOT their total profit.

    Therefore, greedy works here.

    If every activity had a profit and we wanted
    maximum total profit, we would need
    Weighted Interval Scheduling (DP + Binary Search).


    TIME COMPLEXITY:
    ----------------
    Sorting:
        O(N log N)

    Traversing all activities:
        O(N)

    Total:
        O(N log N)


    SPACE COMPLEXITY:
    -----------------
    O(N) for storing the activities.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    // Store activities as:
    // {start_time, end_time}
    vector<pair<int, int>> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }


    /*
        STEP 1:
        Sort activities according to END TIME.

        Example:

        Before:
            [2,5]
            [1,3]
            [4,6]

        After:
            [1,3]
            [2,5]
            [4,6]
    */

    sort(a.begin(), a.end(), [](auto x, auto y) {

        // Compare ending times
        return x.second < y.second;
    });


    /*
        STEP 2:
        Greedily select activities.

        lastEnd = ending time of the
                  last selected activity.

        Initially, no activity has been selected,
        so we can use a very small value.
    */

    int ans = 0;
    int lastEnd = -1;


    /*
        STEP 3:
        Iterate through activities in increasing
        order of ending time.

        If:

            start >= lastEnd

        then the current activity does not overlap
        with the previously selected activity.

        So we select it.
    */

    for(auto [start, end] : a) {

        // Current activity is compatible
        // with the previously selected activity
        if(start >= lastEnd) {

            // Select this activity
            ans++;

            // Update the end time of our
            // last selected activity
            lastEnd = end;
        }
    }


    // Maximum number of non-overlapping activities
    cout << ans << '\n';

    return 0;
}