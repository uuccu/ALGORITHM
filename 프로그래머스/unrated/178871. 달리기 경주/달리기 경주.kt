
class Solution {
    fun solution(players: Array<String>, callings: Array<String>): Array<String> {
        var answer: Array<String> = arrayOf<String>()

        var index = 0
        val length = players.size
        var playersByName = players.associateWith { index++}.toMutableMap()

        callings.forEach {
            val num = playersByName[it]!!

            val name1 = players[num]
            val name2 = players[num - 1]

            players[num] = name2
            players[num - 1] = name1

            playersByName[name1] = num - 1
            playersByName[name2] = num
        }

        answer = players


        return answer
    }
}