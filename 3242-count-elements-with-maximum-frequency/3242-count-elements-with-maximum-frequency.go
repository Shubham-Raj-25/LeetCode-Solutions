import "math"
import "fmt"

func maxFrequencyElements(nums []int) int {
    map_1 := make(map[int]int)
    maxi := 0

    for i := 0; i < len(nums); i++ {
        map_1[nums[i]]++
        maxi = int(math.Max(float64(maxi), float64(map_1[nums[i]])))
    }
    ans := 0

    for _, value := range map_1{
        if(value == maxi){
            ans += value
        }
    }

    return ans
}
