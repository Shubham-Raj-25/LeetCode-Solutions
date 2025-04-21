func numberOfArrays(differences []int, lower int, upper int) int {
    min := 0
    max := 0
    cumulative := 0
    for _, val := range differences {
        cumulative += val
        if cumulative < min {
            min = cumulative
        }
        if cumulative > max {
            max = cumulative
        }
    }
    return maxInt(0, (upper - max) - (lower - min) + 1)
}

func maxInt(a, b int) int {
    if a > b {
        return a
    }
    return b
}


/*

find cumulative min and max?

differences = [1, -3, 4], lower = 1, upper = 6

X, X+1, X-2, X+2
min X-> 3
max X-> 4

min should be greater than lower
max should be less thah upper

No of Xs that satisfy the below
    X+min >= lower && X+max <= upper
    X >= lower-min && X <= upper-max
    => no of Xs upper-max - (lower-min) + 1    

ranges from lower+min -> lower+max


*/ 