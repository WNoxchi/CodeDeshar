import random as rand
import string

class AdoptionCenter:
    """
    The AdoptionCenter class stores the important information that a
    client would need to know about, such as the different numbers of
    species stored, the location, and the name. It also has a method to adopt a pet.
    """
    def __init__(self, name, species_types, location):
        # name: name of adoption center | location: tuple represents x & y as float coordinates
        # species_type: string:integer dictionary of species : number of animals
        self.name = name
        self.location = (float(location[0]), float(location[1]))
        self.species_types = species_types.copy()
    def get_number_of_species(self, animal):
        # returns number of a given species in center
        try:
            return self.species_types[animal]
        except:
            return 0
    def get_location(self):
        # returns locaiton of center
        return self.location
    def get_species_count(self):
        # returns a copy of full list and count of available species at center
        return self.species_types.copy()
    def get_name(self):
        # returns name of center
        return self.name
    def adopt_pet(self, species):
        # decrements value of specific species at center
        if (self.species_types[species]) > 1:
            self.species_types[species] -= 1
        else:
            self.species_types.pop(species)
        return None


class Adopter:
    """
    Adopters represent people interested in adopting a species.
    They have a desired species type that they want, and their score is
    simply the number of species that the shelter has of that species.
    """
    def __init__(self, name, desired_species):
        # name: name of adopter | desired_species: desired species to adopt
        self.name = name
        self.desired_species = desired_species
    def get_name(self):
        # returns adopter name
        return self.name
    def get_desired_species(self):
        # retrusn desired species of adopter
        return self.desired_species
    def get_score(self, adoption_center):
        # returns score
        num_desired = adoption_center.get_number_of_species(self.desired_species)
        score = 1.0 * num_desired
        return score


class FlexibleAdopter(Adopter):
    """
    A FlexibleAdopter still has one type of species that they desire,
    but they are also alright with considering other types of species.
    considered_species is a list containing the other species the adopter will consider
    Their score should be 1x their desired species + .3x all of their desired species
    """
    # Your Code Here, should contain an __init__ and a get_score method.
    def __init__(self, name, desired_species, considered_species):
        Adopter.__init__(self, name, desired_species)
        # considered species is a list, if only string inputted, make into 1 elmt list:
        #if str(type(considered_species)) == "<type 'str'>":    #alt way
        #if isinstance(considered_species, str):                #alt way
        if type(considered_species) == 'str':
            self.considered_species = [considered_species]
        else:
            self.considered_species = considered_species
    def get_score(self, adoption_center):
        adopter_score = Adopter.get_score(self, adoption_center)
        num_other = 0
        for animal in self.considered_species:
            num_other += adoption_center.get_number_of_species(animal)
        score = adopter_score + 0.3 * num_other
        return score


class FearfulAdopter(Adopter):
    """
    A FearfulAdopter is afraid of a particular species of animal.
    If the adoption center has one or more of those animals in it, they will
    be a bit more reluctant to go there due to the presence of the feared species.
    Their score should be 1x number of desired species - .3x the number of feared species
    """
    # Your Code Here, should contain an __init__ and a get_score method.
    def __init__(self, name, desired_species, feared_species):
        Adopter.__init__(self, name, desired_species)
        if type(feared_species) == 'str':
            self.feared_species = [feared_species]
        else:
            self.feared_species = feared_species
    def get_score(self, adoption_center):
        adopter_score = Adopter.get_score(self, adoption_center)
        num_feared = 0
        for animal in self.feared_species:
            num_feared += adoption_center.get_number_of_species(animal)
        score = adopter_score - 0.3 * num_feared
        if score < 0: score = 0.0
        return score


class AllergicAdopter(Adopter):
    """
    An AllergicAdopter is extremely allergic to a one or more species and cannot
    even be around it a little bit! If the adoption center contains one or more of
    these animals, they will not go there.
    Score should be 0 if the center contains any of the animals, or 1x number of desired animals if not
    """
    # Allergic Adopter cannot go to center containing any animals they're allergic to
    def __init__(self, name, desired_species, allergic_species):
        Adopter.__init__(self, name, desired_species)
        if type(allergic_species) == 'str':
            self.allergic_species = [allergic_species]
        else:
            self.allergic_species = allergic_species
    def get_score(self, adoption_center):
        score = 1
        for animal in self.allergic_species:
            if adoption_center.get_number_of_species(animal) > 0:
                score = 0.0
        if score != 0.0:
            return Adopter.get_score(self, adoption_center)
        else:
            return score


class MedicatedAllergicAdopter(AllergicAdopter):
    """
    A MedicatedAllergicAdopter is extremely allergic to a particular species
    However! They have a medicine of varying effectiveness, which will be given in a dictionary
    To calculate the score for a specific adoption center, we want to find what is the most allergy-inducing species that the adoption center has for the particular MedicatedAllergicAdopter.
    To do this, first examine what species the AdoptionCenter has that the MedicatedAllergicAdopter is allergic to, then compare them to the medicine_effectiveness dictionary.
    Take the lowest medicine_effectiveness found for these species, and multiply that value by the Adopter's calculate score method.
    """
    # medicice effectiveness is a dictinoary of {string:float}+
    def __init__(self, name, desired_species, allergic_species, medicine_effectiveness):
        AllergicAdopter.__init__(self, name, desired_species, allergic_species)
        if type(medicine_effectiveness) == 'str':
            self.medicine_effectiveness = [medicine_effectiveness]
        else:
            self.medicine_effectiveness = medicine_effectiveness
    def get_score(self, adoption_center):
        resistance_factor = 1.0
        score = Adopter.get_score(self, adoption_center)
        allergic_adoption = []
        for animal in self.allergic_species:
            if adoption_center.get_number_of_species(animal) > 0:
                allergic_adoption.append(animal)
        for animal in allergic_adoption:
            try:
                new_resistance_factor = self.medicine_effectiveness[animal]
            except:
                new_resistance_factor = 0.0
            if new_resistance_factor < resistance_factor:
                resistance_factor = new_resistance_factor
        return (score * resistance_factor)



class SluggishAdopter(Adopter):
    """
    A SluggishAdopter really dislikes travelleng. The further away the
    AdoptionCenter is linearly, the less likely they will want to visit it.
    Since we are not sure the specific mood the SluggishAdopter will be in on a
    given day, we will asign their score with a random modifier depending on
    distance as a guess.
    Score should be
    If distance < 1 return 1 x number of desired species
    elif distance < 3 return random between (.7, .9) times number of desired species
    elif distance < 5. return random between (.5, .7 times number of desired species
    else return random between (.1, .5) times number of desired species
    """
    # Your Code Here, should contain an __init__ and a get_score method.
    def __init__(self, name, desired_species, location):
        Adopter.__init__(self, name, desired_species)
        self.start_location = (float(location[0]), float(location[1]))
    # calcs linear distance btwn 2 points
    def get_linear_distance(self, to_location):
        import math
        destination = to_location.get_location()
        distance = math.sqrt((destination[0] - self.start_location[0])**2 + (destination[1] - self.start_location[1])**2)
        return distance
    def get_score(self, adoption_center):
        import random as rand
        prelim_score = Adopter.get_score(self, adoption_center)
        distance = self.get_linear_distance(adoption_center)
        if distance < 1.0:
            score_factor = 1.0
        elif distance < 3.0 and distance >= 1.0:
            score_factor = rand.uniform(0.7, 0.9)
        elif distance < 5.0 and distance >= 3.0:
            score_factor = rand.uniform(0.5, 0.7)
        elif distance >= 5.0:
            score_factor = rand.uniform(0.1, 0.5)
        score = prelim_score * score_factor
        return score




def get_ordered_adoption_center_list(adopter, list_of_adoption_centers):
    """
    The method returns a list of an organized adoption_center such that the scores for each AdoptionCenter to the Adopter will be ordered from highest score to lowest score.
    """
    # Your Code Here
    ordered_center_list = []
    score_center_list = {}
    for adoption_center in len(list_of_adoption_centers):
        score_center_list[adoption_center] = get_score(adopter, adoption_center)
    for

def get_adopters_for_advertisement(adoption_center, list_of_adopters, n):
    """
    The function returns a list of the top n scoring Adopters from list_of_adopters (in numerical order of score)
    """
    # Your Code Here
