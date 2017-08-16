T = int(input())
for _ in range(T):
    teams = set()
    losers = set()
    for i in range(16):
        teamA, teamB, scoreA, scoreB = raw_input().split()
        teams.add(teamA)
        teams.add(teamB)
        if int(scoreA) > int(scoreB):
            losers.add(teamB)
        else:
            losers.add(teamA)
    for t in teams:
        if t not in losers:
            print(t)
        break
