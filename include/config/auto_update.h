// These config are only used by some preprocessing script and are not used in the game code
// They are presented here for the sake of consistency

#define MAKE_AUTO_UPDATE_ACTIVE          TRUE       // if TRUE, whenever you compile and match the other configured requirements, a script will look for expansion updates and apply them to your repo (it will not solve conflicts but we will automatically run migration scripts)
#define MAKE_AUTO_UPDATE_REMOTE_BRANCH   "upcoming" // remote branch the auto update will fetch from, it's recommended to only use "upcoming" or "master"
#define MAKE_AUTO_UPDATE_FREQUENCY       ALL        // Must be one of (ALL, DAILY, WEEKLY, MONTHLY)
#define MAKE_AUTO_UPDATE_LOCAL_BRANCHES  ".+" // the branches that you must be in to trigger the update, this field accept regular expression
