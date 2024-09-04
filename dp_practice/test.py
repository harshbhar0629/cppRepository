import random

class CricketGame:

    def __init__(self, teamA, teamB):
        self.teamA = teamA
        self.teamB = teamB
        self.teamA_wins = 0
        self.teamB_wins = 0

    def stimulate_match(self):
        winner = random.choice([self.teamA, self.teamB])
        if winner == self.teamA:
            self.teamA_wins += 1
        else:
            self.teamB_wins += 1
        return winner

    def stimulate_series(self, num_matches):
        for _ in range(num_matches):
            self.stimulate_match()

        if self.teamA_wins > self.teamB_wins:
            return {
                'winner': self.teamA,
                'matches_won': self.teamA_wins
            }
        elif self.teamA_wins < self.teamB_wins:
            return {
                'winner': self.teamB,
                'matches_won': self.teamB_wins
            }
        else:
            return {
                'winner': "Draw",
                'matches_won': None
            }

def get_series_winner(num_matches):
    game = CricketGame("TeamA", "TeamB")
    return game.stimulate_series(num_matches)

num_matches = 9
series_result = get_series_winner(num_matches)
print(f"series_winner: {series_result['winner']}, matches_won= {series_result['matches_won']}")
