
class Player:
    # Class variable to track how many players are created
    player_count = 0

    def __init__(self, name, level):
        # Instance variables
        self.name = name
        self.level = level

        # Every time a new player object is created, increase count
        Player.player_count += 1

    def display_info(self):
        print(f"Player Name: {self.name}")
        print(f"Player Level: {self.level}")

   
    def total_players(self):
        print(f"Total Players Created: {Player.player_count}")


P1=Player("Neymar",10)
P1.total_players()