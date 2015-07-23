from league_object import LeagueObject


class Champion(LeagueObject):
    def __init__(self, engine, list_index):
        super(Champion, self).__init__(engine, list_index)

    def get_fields(self):
        properties = {}
        properties.update(super(Champion, self).get_fields())
        return properties