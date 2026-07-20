## Hot to use the battle status menu

The Battle Status Meny is a replica from modern games. 
It shows the current snapshot of the battle. 
That includes pokemon's stat stages, volatile conditions, 
ability/item for the player side, and field statuses.

-- TODO: explain the enums and description
### How to add new field statuses or volatiles to the menu

#### 1. Adding new battler volatiles 
There are 3 options
```C
static void TryAddActiveStatus(
                enum BattleStatus status, 
                u32 status, 
                enum BattleSide side
            );
```
`TryAddActiveStatus` is used for volatiles without a timer, meaning they persist until the battle is over
Also used when a timer is unknown
```C

static void TryAddActiveStatusTimer(
                enum BattleStatus status, 
                u32 remaining, 
                u32 baseTotal, 
                enum BattleSide side
            );
```
`TryAddActiveStatusTimer` one is used for volatiles that expire. 
`remaining` is the time until it runs out. 
`baseTotal` is the maximum amount of turns.

#### 2. Field conditions
```C
static void TryAddActiveFieldStatus(
                enum BattleStatus status, 
                u32 fieldStatus, 
                u32 timer, 
                u32 totalTimer, 
                enum BattleSide side
            );
```
`TryAddActiveFieldStatus` is used for field statuses like Trick Room.
If it's a permanent status, the timer will be ignored so the values passed can be zero.

```C
static void TryAddActiveSideStatus(
                enum BattleStatus status, 
                u32 sideStatus, 
                u32 timer, 
                u32 totalTimer, 
                enum BattleSide side
            );
```
`TryAddActiveSideStatus` is used  for side status like Light Screen.
As previously, if it's a permanent status, the timer will be ignored so the values passed can be zero.

### 3. Weather and Terrain
Weather and Terrain have extra functions, `TryAddActiveWeather` and `TryAddActiveTerrain`.
If a new weather/terrain are added, the compiler will usually throw an error to add it.
That means that those can be mostly just ignored.
