/*
 *  /GCGameState.h
 *  gusimplewhiteboard / clfsm
 *
 *  Created by Rene Hexel on 25/03/13.
 *  Copyright (c) 2013, 2014 Rene Hexel. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Rene Hexel.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
#ifndef GCGameState_DEFINED
#define GCGameState_DEFINED

#include <cstdlib>
#include <stdint.h>
#include <sys/types.h>
#include <sstream>
#include <gu_util.h>

#define SPL_NUM_PLAYERS 6
#define SPL_NUM_TEAMS 2

#define DEFAULT_PLAYER_NUMBER 2

#define MIPAL_TEAM_NO 11  // MiPal's SPL assigned Team number, persisting from 2013)

#define kGSTeamHome "HomeTeam"
#define kGSTeamAway "AwayTeam"

#define kGSFirstHalf "FirstHalf"
#define kGSSecondHalf "SecondHalf"

#define kGSNormalGame "NormalGame"
#define kGSMixedTeam "MixedTeams"
#define kGSDropIn "Drop In"

#define kGSPenaltyShots "PenaltyShots"
#define kGSOverTime "OverTime"
#define kGSTimeOut "TimeOut"

#define kGSInitialReceived "InitialReceived"
#define kGSReadyReceived "ReadyReceived"
#define kGSSetReceived "SetReceived"
#define kGSPlayingReceived "PlayingReceived"
#define kGSFinishedReceived "FinishedReceived"

#define kGSInitial "GSInitial"
#define kGSReady "GSReady"
#define kGSSet  "GSSet"
#define kGSPlaying  "GSPlaying"
#define kGSFinished  "GSFinished"

#define kGSNoSetPlay "GSNoSetPlay"
#define kGSGoalFreeKick "GSGoalFreeKick"
#define kGSPushingFreeKick  "GSPushingFreeKick"
#define kGSCornerKick  "GSCornerKick"
#define kGSKickIn  "GSKickIn"


#define kGSNoPenalty "NoPenalty"
#define kGSIllegalBallContact "IllegalBallContact"
#define kGSPlayerPushing "PlayerPushing"
#define kGSIllegalMotionInSet "IllegalMotionInSet"
#define kGSInactivePlayer "InactivePlayer"
#define kGSIllegalDefender "IllegalDefender"
#define kGSLeavingTheField "LeavingTheField"
#define kGSKickOffGoal "KickOffGoal"
#define kGSRequestForPickup "RequestForPickup"
#define kGSLocalGameStuck "LocalGameStuck"
#define kGSIllegalPositioning "IllegalPositioning"
#define kGSSubstitutionPenalty "SubstitutionPenalty"
#define kGSManualPenalty "ManualPenalty"


#define kNoGSsignal "NoGSsignal"
#define kGSOurGoalSignalPushed "GSOurGoalSignalPushed"
#define kGSTheirGoalSignalPushed "GSTheirGoalSignalPushed"
#define kGSBlueKickOffSignalPushed "GSBlueKickOffSignalPushed"
#define kGSRedKickOffSignalPushed "GSRedKickOffSignalPushed"

namespace guWhiteboard
{
  // Variables prescribed by the Game Controller
  
  /// Team Colours
  enum TeamColors : int8_t
  { BLUE=0, RED, YELLOW, BLACK, WHITE, GREEN, ORANGE, PURPLE, BROWN, GRAY, NUM_JERSEY_COLORS };
  
  /// Team Colour strings
  static const char *teamColorsStr[NUM_JERSEY_COLORS] =
  { "Blue", "Red", "Yellow", "Black", "White", "Green", "Orange", "Purple", "Brown", "Gray" };

  /// Type of the competition
  enum CompetitionType : int8_t
  //  { NormalCompetition, MixedTeam, GeneralPenaltyKick, NUM_COMPETITION_TYPES };
  { NormalCompetition, MixedTeam, NUM_COMPETITION_TYPES };
  
  /// Phase of the competition
  enum CompetitionPhase : int8_t
  { RoundRobin, PlayOff, NUM_COMPETITION_PHASES };
  
  /// Phase of the game
  enum GamePhase : int8_t
  { NormalPhase, PenaltyShoot, Overtime, Timeout };
  
  /// High level Game Controller states
  enum GameState : int8_t
  { Initial, Ready, Set, Playing, Finished, NUM_GAME_STATES };

  /// Set play codes
  enum SetPlay : int8_t
  { NoSetPlay, GoalFreeKick, PushingFreeKick, CornerKick, KickIn, NUM_SET_PLAY_TYPES };

  /// Penalty types
  enum PenaltyTypes : int8_t
  // OUR OLD FORMAT (CoachMotion removed)
  //  { NoPenalty = 0, BallHolding, PlayerPushing, IllegalMotionInSet, InactivePlayer, IllegalDefender, LeavingTheField,
  //    KickOffGoal, RequestForPickup, CoachMotion, PenaltySubstitute = 14, ManualButtonPenalty = 15};
  { NoPenalty = 0,
    IllegalBallContact,
    PlayerPushing,
    IllegalMotionInSet,
    InactivePlayer,
    IllegalDefender,
    LeavingTheField,
    KickOffGoal,
    RequestForPickUp,
    LocalGameStuck,      // New Penalty Code
    IllegalPositioning,  // New Penalty Code
    SubstitutionPenalty = 14,
    ManualPenalty = 15
  };

  struct RobotPenaltyState
  {
    PenaltyTypes penalty;         // penalty state of the player
    uint8_t secsTillUnpenalised;  // estimate of time till unpenalised
  };

  
  // Definitions used internally to make sense of the game.

  /// Used to nominate which team is home/away and to decouple game state from team specifics
  enum HomeAway : int8_t
  { Home=0, Away=1 };

  /// Soccer games comprise of two halves
  enum GameHalf : int8_t
  { SecondHalf, FirstHalf };

  /// Who kicked the ball out
  enum BallOut : int8_t
  { OutByHome, OutByAway };

  /// received command from the Game Controller
  enum GameControllerCommand : int8_t
  { InitialReceived, ReadyReceived, SetReceived, PlayingReceived, FinishedReceived };

    /// major game event signals (goals, kick-offs)
	enum GameContollerSignal : int8_t
	{  NoGSsignal, GSOurGoalSignalPushed, GSTheirGoalSignalPushed, GSBlueKickOffSignalPushed, GSRedKickOffSignalPushed };

  
  
  /**
    * WB Class to record game state received from the Game Controller
    */
  class GCGameState {

  private:
    /// Penalty state of each robot in the game
    RobotPenaltyState  _RobotGCPenaltyState[SPL_NUM_TEAMS][SPL_NUM_PLAYERS];

    /// Current score
    int16_t _score[SPL_NUM_TEAMS];

    /// GC half
    PROPERTY(GameHalf, theGCHalf)

    /// GC compeition type
    PROPERTY(CompetitionType, theGCCompetitionType)

    /// GC competition phase
    PROPERTY(CompetitionPhase, theGCCompetitionPhase)

    /// GC game phase
    PROPERTY(GamePhase, theGCGamePhase)

    /// GC high level game state
    PROPERTY(GameState, theGCGameState)

//    /// GC GameControllerCommand
//    PROPERTY(GameControllerCommand, theGCCommand)

    ///  GC active set play
    PROPERTY(SetPlay, theGCSetPlayInProgress)

    ///  GC team that has next free kick (kickoff, kickin, etc.)
    PROPERTY(HomeAway, theGCTeamWithFreeKick)

    /// number of seconds remaining in the current half of the game
    PROPERTY(int16_t, secondsReminingInHalf )

    ///  Our home/away designation
    PROPERTY(HomeAway, homeaway )

  public:
    /** designated constructor */
    GCGameState(
                GameHalf theGCHalf = FirstHalf,
                CompetitionType theGCCompetitionType = NormalCompetition,
                CompetitionPhase theGCCompetitionPhase = RoundRobin,
                GamePhase theGCGamePhase = NormalPhase,
                GameState theGCGameState = Initial,
                SetPlay theGCSetPlayInProgress = NoSetPlay,
                HomeAway theGCTeamWithFreeKick = Home,
                int16_t secondsReminingInHalf = Home,
                HomeAway homeaway = Home
    ):
      _theGCHalf(theGCHalf),
      _theGCCompetitionType(theGCCompetitionType),
      _theGCCompetitionPhase(theGCCompetitionPhase),
      _theGCGamePhase(theGCGamePhase),
      _theGCGameState(theGCGameState),
      _theGCSetPlayInProgress(theGCSetPlayInProgress),
      _theGCTeamWithFreeKick(theGCTeamWithFreeKick),
      _secondsReminingInHalf(secondsReminingInHalf),
      _homeaway(homeaway)
    {
      for (int i=0; i< SPL_NUM_TEAMS; i++) {
        for (int j=0; j< SPL_NUM_PLAYERS; j++) {
          _RobotGCPenaltyState[i][j].penalty = NoPenalty;
          _RobotGCPenaltyState[i][j].secsTillUnpenalised = 0;
        }
      }
      for (int i=0; i< SPL_NUM_TEAMS; i++) _score[i] = 0;
    }

    /** string constructor */
    GCGameState(const std::string &names) { from_string(names); }

    /** copy constructor */
    GCGameState(const GCGameState &other):
      _theGCHalf(other._theGCHalf),
      _theGCCompetitionType(other._theGCCompetitionType),
      _theGCCompetitionPhase(other._theGCCompetitionPhase),
      _theGCGamePhase(other._theGCGamePhase),
      _theGCGameState(other._theGCGameState),
      _theGCSetPlayInProgress(other._theGCSetPlayInProgress),
      _theGCTeamWithFreeKick(other._theGCTeamWithFreeKick),
      _secondsReminingInHalf(other._secondsReminingInHalf),
      _homeaway(other._homeaway)
    {
      for (int i=0; i< SPL_NUM_TEAMS; i++) {
				for (int j=0; j< SPL_NUM_PLAYERS; j++) {
          _RobotGCPenaltyState[i][j].penalty = other._RobotGCPenaltyState[i][j].penalty;
          _RobotGCPenaltyState[i][j].secsTillUnpenalised = other._RobotGCPenaltyState[i][j].secsTillUnpenalised;
				}
	    }
			for (int i=0; i< SPL_NUM_TEAMS; i++) _score[i]=other._score[i];
    }

    /** assignment operator */
    const GCGameState &operator=(const GCGameState &other) { memcpy(this, &other, sizeof(*this)); return *this; }
 
    /** Set the Penalty vectors */
	  void setPenaltyVectors(const RobotPenaltyState robotGCPenaltyState[SPL_NUM_TEAMS][SPL_NUM_PLAYERS]) {
      for (int i=0; i< SPL_NUM_TEAMS; i++) {
        for (int j=0; j< SPL_NUM_PLAYERS; j++) {
          _RobotGCPenaltyState[i][j].penalty=robotGCPenaltyState[i][j].penalty;
          _RobotGCPenaltyState[i][j].secsTillUnpenalised=robotGCPenaltyState[i][j].secsTillUnpenalised;
        }
      }
    }

    /** Set the score */
    void setScore(int16_t goalsByHome, int16_t goalsByAway) {
      _score[Home] = goalsByHome;
      _score[Away] = goalsByAway;
		}

    /** getter for the Home team's score  */
		int16_t getScoreHome() { return _score[Home]; }
    
    /** getter for the Away team's score  */
		int16_t getScoreAway() { return _score[Away]; }

    /** getter for our score  */
		int16_t getOurScore() { return _score[_homeaway]; }
    
    /** getter the other team's score  */
		int16_t getTheirScore() { 
      if (Home == _homeaway ) return getScoreAway();
			else return getScoreHome();
    }

    /** getter for the penalty state of one of our robots   */
		RobotPenaltyState myPenaltyStateIs (int PlayerNumber)
		{
      // the index in the structure starts at 0 but robot numbers start with 1
      if ((0<PlayerNumber) && (PlayerNumber<=SPL_NUM_PLAYERS ))
        return static_cast<RobotPenaltyState>(_RobotGCPenaltyState[_homeaway][PlayerNumber-1]);
      RobotPenaltyState noPenalty;
      noPenalty.penalty = NoPenalty;
      noPenalty.secsTillUnpenalised = 0;
      return noPenalty;
		}

    /** getter for the penalty state of one of our robots   */
    PenaltyTypes myPenaltyIs (int PlayerNumber)
    {
      // the index in the structure starts at 0 but robot numbers start with 1
      if ((0<PlayerNumber) && (PlayerNumber<=SPL_NUM_PLAYERS ))
        return static_cast<PenaltyTypes>(_RobotGCPenaltyState[_homeaway][PlayerNumber-1].penalty);
      return NoPenalty;
    }

    /** Is our robot currently penalised */
		bool amIPenalized(int PlayerNumber)
		{
			if (NoPenalty==myPenaltyIs(PlayerNumber))
			   return false;
			else return true;
		}

    /** Setter for penalty state of our robot  */
		void setMyPenalty(int PlayerNumber, PenaltyTypes thePenalty, uint8_t duration = 0) {
      _RobotGCPenaltyState[_homeaway][PlayerNumber-1].penalty=thePenalty;
      _RobotGCPenaltyState[_homeaway][PlayerNumber-1].secsTillUnpenalised = duration;
    }

    /** convert to a string */
    std::string description() {
      std::ostringstream ss;
      if  ( Home == homeaway() ) ss << kGSTeamHome << ","; else ss << kGSTeamAway << ",";
      switch(int (_theGCSetPlayInProgress)) {
        case NoSetPlay:
          ss << kGSNoSetPlay << ",";
          break;
        case GoalFreeKick:
          ss << kGSGoalFreeKick << ",";
          break;
        case PushingFreeKick:
          ss << kGSPushingFreeKick << ",";
          break;
        case CornerKick:
          ss << kGSCornerKick << ",";
          break;
        case KickIn:
          ss << kGSKickIn << ",";
          break;
        default:
          ss << _theGCSetPlayInProgress << ",";
      }


      ss << "Next kick to: ";
      if  ( Home == theGCTeamWithFreeKick() ) ss << kGSTeamHome << ","; else ss << kGSTeamAway << ",";
      if  ( FirstHalf == theGCHalf() ) ss << kGSFirstHalf << ","; else ss << kGSSecondHalf << ",";
      if  ( NormalCompetition == theGCCompetitionType()) ss << kGSNormalGame << ","; else ss << kGSMixedTeam << ",";

      switch(int (_theGCGameState)) {
        case Initial:
          ss << kGSInitial << ",";
          break;
        case Ready:
          ss << kGSReady << ",";
          break;
        case Set:
          ss << kGSSet << ",";
          break;
        case Playing:
          ss << kGSPlaying << ",";
          break;
        case Finished:
          ss << kGSFinished << ",";
          break;
        default:
          ss << _theGCGameState << ",";
      }
      for (int i=0; i< SPL_NUM_PLAYERS; i++)
      {
        switch (_RobotGCPenaltyState[_homeaway][i].penalty ) {
          case NoPenalty :
            ss << kGSNoPenalty << ", - ," ;
            break;
          case IllegalBallContact :
            ss << kGSIllegalBallContact << ",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case PlayerPushing :
            ss << kGSPlayerPushing<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case IllegalMotionInSet :
            ss << kGSIllegalMotionInSet<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case InactivePlayer :
            ss << kGSInactivePlayer<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case IllegalDefender :
            ss << kGSIllegalDefender<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case LeavingTheField :
            ss << kGSLeavingTheField<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case KickOffGoal :
            ss << kGSKickOffGoal<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case RequestForPickUp :
            ss << kGSRequestForPickup<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case LocalGameStuck :
            ss << kGSLocalGameStuck<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case IllegalPositioning :
            ss << kGSIllegalPositioning<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case SubstitutionPenalty :
            ss << kGSSubstitutionPenalty<<",";
            ss << " (" << _RobotGCPenaltyState[_homeaway][i].secsTillUnpenalised << ") ,";
            break;
          case ManualPenalty :
            ss << kGSManualPenalty << ", - ," ;
            break;
        }
      }
        ss << getScoreHome() << "," <<  getScoreAway() << ",";
        return ss.str();
      }

      /** TODO: convert from a string */
      void from_string(const std::string &str) {
        std::istringstream iss(str);
        std::string token;
        getline(iss, token, ',');
      }
    };
}
#endif // GCGameState_DEFINED
