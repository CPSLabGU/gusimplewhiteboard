/*
 *  /UDPReceiverNotification.h
 *  gusimplewhiteboard / clfsm
 *
 *  Created by Rene Hexel on 25/03/13.
 *  Copyright (c) 2013 Rene Hexel. All rights reserved.
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
#ifndef UDPReceiverNotification_DEFINED
#define UDPReceiverNotification_DEFINED

#include <cstdlib>
#include <sstream>
#include <gu_util.h>

#define SPL_NUM_PLAYERS 5
#define SPL_NUM_TEAMS 2

#define DEFAULT_PLAYER_NUMBER 2

#define kUDPTeamBlue "TeamBlue"
#define kUDPTeamRed "TeamRed"

#define kUDPFirstHalf "FirstHalf"
#define kUDPSecondHalf "SecondHalf"

#define kUDPNormalGame "NormalGame"
#define kUDPPenaltyShots "PenaltyShots"
#define kUDPOverTime "OverTime"

#define kUDPInitialReceived "InitialReceived"
#define kUDPReadyReceived "ReadyReceived"
#define kUDPSetReceived "SetReceived"
#define kUDPPlayingReceived "PlayingReceived"
#define kUDPFinishedReceived "FinishedReceived"

#define kUDPInitial "UDPInitial"
#define kUDPReady "UDPReady"
#define kUDPSet  "UDPSet"
#define kUDPPlaying  "UDPPlaying"
#define kUDPFinished  "UDPFinished"

#define kUDPNoPenalty "NoPenalty"
#define kUDPBallHolding "BallHolding"
#define kUDPPlayerPushing "PlayerPushing"
#define kUDPObstruction "Obstruction"
#define kUDPInactivePlayer "InactivePlayer"
#define kUDPIllegalDefender "IllegalDefender"
#define kUDPLeavingTheField "LeavingTheField"
#define kUDPPlayingWithHands "PlayingWithHands"
#define kUDPRequestForPickup "RequestForPickup"


#define kNoUDPsignal "NoUDPsignal"
#define kUDPOurGoalSignalPushed "UDPOurGoalSignalPushed"
#define kUDPTheirGoalSignalPushed "UDPTheirGoalSignalPushed"
#define kUDPBlueKickOffSignalPushed "UDPBlueKickOffSignalPushed"
#define kUDPRedKickOffSignalPushed "UDPRedKickOffSignalPushed"

namespace guWhiteboard
{
	enum TeamColors
	{  TeamBlue=0, TeamRed=1, SentinelTeamColors=SPL_NUM_TEAMS };

	enum GameHalf
	{  SecondHalf, FirstHalf };

	enum GameFormat
	{  NormalGame, PenaltyShots, OverTime };

	enum BallOut
	{  OutByBlue, OutByRed };

	enum GameState {  Initial, Ready, Set, Playing, Finished };

	enum GameContollerCommand
	{  InitialReceived, ReadyReceived, SetReceived, PlayingReceived, FinishedReceived };

	enum PenaltyFormat
	{ NoPenalty, BallHolding, PlayerPushing, Obstruction, InactivePlayer, IllegalDefender, LeavingTheField, PlayingWithHands, RequestForPickup };

	enum GameContollerSignal
	{  NoUDPsignal, UDPOurGoalSignalPushed, UDPTheirGoalSignalPushed, UDPBlueKickOffSignalPushed, UDPRedKickOffSignalPushed };

        /**
	 * Class to annoucne to out class-oriented whiteboard what we got in UDPreceiver
         */

        class UDPReceiverNotification
        {
	   private:
		 PenaltyFormat _whatPenaltyFromUsInUDPgameController[SPL_NUM_PLAYERS];
		 PenaltyFormat _whatPenaltyFromThemInUDPgameController[SPL_NUM_PLAYERS];

		 int16_t _score [SentinelTeamColors];
		 bool _dropInTeam;

                PROPERTY(GameHalf, theUDPHalf )  //  UDP half
                PROPERTY(GameFormat, theUDPGameformat )  //  UDP game format
                PROPERTY(GameState, theUDPGameState )  
		//  UDP GameContollerCommand
                PROPERTY(GameContollerCommand, theUDPGameContollerCommand )  
		//  UDP team that ahs kickoff
                PROPERTY(TeamColors, theUDPteamThatHasKickOf )  

        public:
            /** designated constructor */
            UDPReceiverNotification(GameHalf theUDPHalf = FirstHalf, 
                                       GameFormat theUDPGameformat = NormalGame,
				       GameState theUDPGameState = Initial,
				       TeamColors theUDPteamThatHasKickOf = TeamBlue 
                                       //GameContollerCommand theUDPGameContollerCommand =InitialReceived,
                                       //GameContollerSignal theUDPGameContollerSignal = NoUDPsignal
				       ):
                                      _theUDPHalf(theUDPHalf), 
                                      _theUDPGameformat(theUDPGameformat),
                                      _theUDPGameState(theUDPGameState),
                                      _theUDPteamThatHasKickOf(theUDPteamThatHasKickOf)
                                      //_theUDPGameContollerSignal(theUDPGameContollerSignal
                                        {
			for (int i=0; i< SPL_NUM_PLAYERS; i++)
			{
				_whatPenaltyFromUsInUDPgameController[i]=NoPenalty;
				_whatPenaltyFromThemInUDPgameController[i]=NoPenalty;
			}
			_dropInTeam=false;
			for (TeamColors i=TeamBlue; i< SentinelTeamColors; i++) _score[i]=0;
                }

            /** string constructor */
            UDPReceiverNotification(const std::string &names) { from_string(names); }

            /** copy constructor */
            UDPReceiverNotification(const UDPReceiverNotification &other):
                      _theUDPHalf(other._theUDPHalf),
                      _theUDPGameformat(other._theUDPGameformat),
                       _theUDPGameState(other._theUDPGameState),
                       _theUDPteamThatHasKickOf(other._theUDPteamThatHasKickOf)
                      //_theUDPGameContollerCommand(other._theUDPGameContollerCommand),
                      //_theUDPGameContollerSignal(other._theUDPGameContollerSignal
                       { for (int i=0; i< SPL_NUM_PLAYERS; i++)
			{
				_whatPenaltyFromUsInUDPgameController[i]=other._whatPenaltyFromUsInUDPgameController[i];
				_whatPenaltyFromThemInUDPgameController[i]=other._whatPenaltyFromThemInUDPgameController[i];
			}
			_dropInTeam=other._dropInTeam;
			for (int i=0; i< SPL_NUM_TEAMS; i++) _score[i]=other._score[i];
                      }

            /** Set the Penalty vectors */
	    void setPenaltyVectors(const PenaltyFormat thePenaltyFromUsInUDPgameController[SPL_NUM_PLAYERS],
		                    const PenaltyFormat thePenaltyFromThemInUDPgameController[SPL_NUM_PLAYERS])
			    {
				    for (int i=0; i<SPL_NUM_PLAYERS; i++)
				    {
						_whatPenaltyFromUsInUDPgameController[i]=thePenaltyFromUsInUDPgameController[i];
						_whatPenaltyFromThemInUDPgameController[i]=thePenaltyFromThemInUDPgameController[i];
				    }
			    }

            /** Set the score */
	    void setScore(int16_t goalsByBlue, int16_t goalsByRed)
		{  _score[TeamBlue] = goalsByBlue;
		   _score[TeamRed] = goalsByRed;
		}

		int16_t getScoreBlue() { return _score[TeamBlue];}
		int16_t getScoreRed() { return _score[TeamRed];}

            /** convert to a string */
            std::string description()
            {
                std::ostringstream ss;
	        if  ( TeamBlue == theUDPteamThatHasKickOf() ) ss << kUDPTeamBlue<<","; else ss << kUDPTeamRed<<",";

	        if  ( FirstHalf == theUDPHalf() ) ss << kUDPFirstHalf<<","; else ss << kUDPSecondHalf<<",";

	        if  ( NormalGame == theUDPGameformat() ) ss << kUDPNormalGame<<","; else ss << kUDPPenaltyShots<<",";

		switch(int (_theUDPGameState))
		{ case Initial: ss << kUDPInitial<<",";
			break;
		  case Ready: ss << kUDPReady<<",";
			break;
		  case Set: ss << kUDPSet<<",";
			break;
		  case Playing: ss << kUDPPlaying<<",";
			break;
		  case Finished: ss << kUDPFinished<<",";
			break;
	          default: ss << _theUDPGameState <<",";
		}


                for (int i=0; i< SPL_NUM_PLAYERS; i++)
		switch (_whatPenaltyFromUsInUDPgameController[i] )
		{ case NoPenalty : ss << kUDPNoPenalty<<",";
			break;
		  case BallHolding : ss << kUDPBallHolding<<",";
			break;
		  case PlayerPushing : ss << kUDPPlayerPushing<<",";
			break;
		  case Obstruction : ss << kUDPObstruction<<",";
			break;
		  case InactivePlayer : ss << kUDPInactivePlayer<<",";
			break;
		  case IllegalDefender : ss << kUDPIllegalDefender<<",";
			break;
		  case LeavingTheField : ss << kUDPLeavingTheField<<",";
			break;
		  case PlayingWithHands : ss << kUDPPlayingWithHands<<",";
			break;
		  case RequestForPickup : ss << kUDPRequestForPickup<<",";
			break;
		}

		ss << getScoreBlue() << "," <<  getScoreRed() << ",";



		/*
		switch (theUDPGameContollerCommand() )
		{ case InitialReceived : ss << kUDPInitialReceived<<",";
			break;
		  case ReadyReceived : ss << kUDPReadyReceived<<",";
			break;
		  case SetReceived : ss << kUDPSetReceived<<",";
			break;
		  case PlayingReceived : ss << kUDPPlayingReceived<<",";
			break;
		  case FinishedReceived : ss << kUDPFinishedReceived<<",";
			break;
		}

		switch (theUDPGameContollerSignal() )
		{ case NoUDPsignal : ss << kNoUDPsignal<<",";
			break;
		  case UDPOurGoalSignalPushed : ss << kUDPOurGoalSignalPushed<<",";
			break;
		  case UDPTheirGoalSignalPushed : ss << kUDPTheirGoalSignalPushed<<",";
			break;
		  case  UDPBlueKickOffSignalPushed: ss << kUDPBlueKickOffSignalPushed<<",";
			break;
		  case UDPRedKickOffSignalPushed : ss << kUDPRedKickOffSignalPushed<<",";
			break;
		}
		*/

                return ss.str();
            }

            /** TODO: convert from a string */
            void from_string(const std::string &str)
            {
                std::istringstream iss(str);
                std::string token;
                getline(iss, token, ',');
            }
        };
}


#endif // UDPReceiverNotification_DEFINED
