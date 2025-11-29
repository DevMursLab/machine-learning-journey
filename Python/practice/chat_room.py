from datetime import datetime

# ==========================
# User Class
# ==========================
class User:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name


# ==========================
# Message Class
# ==========================
class Message:
    def __init__(self, sender, text):
        self.sender = sender        # sender is User object
        self.text = text
        self.time = datetime.now()  # timestamp

    def show(self):
        print(f"[{self.time.strftime('%H:%M:%S')}] {self.sender}: {self.text}")


# ==========================
# ChatRoom Class
# ==========================
class ChatRoom:
    def __init__(self, room_name):
        self.room_name = room_name
        self.users = []
        self.messages = []

    # User Join
    def join_user(self, user):
        self.users.append(user)
        print(f"{user} চ্যাটরুমে যোগ দিলেন!")

    # User Leave
    def leave_user(self, user):
        self.users.remove(user)
        print(f"{user} চ্যাটরুম থেকে বের হয়ে গেলেন!")

    # Send Message
    def send_message(self, user, text):
        if user not in self.users:
            print("⚠ এই ইউজার চ্যাটরুমে নেই!")
            return

        msg = Message(user, text)
        self.messages.append(msg)
        msg.show()

    # View Chat History
    def show_history(self):
        print("\n----- চ্যাট হিস্টোরি -----")
        for msg in self.messages:
            msg.show()
        print("---------------------------\n")


# ============================================================
# Example Usage (Demo)
# ============================================================

room = ChatRoom("Programming Room")

# Create users
u1 = User("Mursalin")
u2 = User("Shuvo")

# Users join
room.join_user(u1)
room.join_user(u2)

# Send messages
room.send_message(u1, "Assalamu Alaikum, সবাই কেমন আছেন?")
room.send_message(u2, "Wa Alaikum Salam! আমি ভালো।")

# Show chat history
room.show_history()

# User leaves
room.leave_user(u2)
