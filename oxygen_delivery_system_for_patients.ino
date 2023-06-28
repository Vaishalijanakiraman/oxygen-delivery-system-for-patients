import random
import time

class Patient:
    def _init_(self, name):
        self.name = name
        self.oxygen_level = 100

    def measure_oxygen_level(self):
        self.oxygen_level -= random.randint(1, 5)

    def deliver_oxygen(self):
        self.oxygen_level += random.randint(1, 5)

    def display_oxygen_level(self):
        print(f"{self.name}'s oxygen level: {self.oxygen_level}%")

def main():
    patients = [
        Patient("John"),
        Patient("Mary"),
        Patient("Alice")
    ]

    monitoring_duration = 60 
    start_time = time.time()

    while time.time() - start_time < monitoring_duration:
        for patient in patients:
            patient.measure_oxygen_level()
            patient.deliver_oxygen()
            patient.display_oxygen_level()

        time.sleep(1)

if _name_ == '_main_':
    main(
