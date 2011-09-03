/*
 *	 TwitCrusader++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader++
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *		Source: https://github.com/RoxShannon/TwitCrusaderpp
 *		email: orazio.1985@hotmail.com
 *
 */

#include "include/TimeLine.h"

namespace TwitCrusader {

vector<Tweet> TwitCrusader::TimeLine::readTimeLine(string fileName)
{

	vector<Tweet> timeline=vector<Tweet>();
	DomParser parser;
	parser.set_substitute_entities();
	parser.parse_file(fileName);
	if(parser)
	{
		const Node* rootNode = parser.get_document()->get_root_node();
		const ustring rootName = rootNode->get_name();

		if(rootName.compare("statuses")==0)
		{

			xmlpp::Node::NodeList status=rootNode->get_children("status");


			for(xmlpp::Node::NodeList::iterator a = status.begin(); a != status.end(); a++){

				const ustring statusname = a.operator *()->get_name();
				cout<<"statusname:\t"<<statusname<<endl;
				xmlpp::Node::NodeList tweet=a.operator *()->get_children();
				Tweet *tw=new Tweet();

				for(xmlpp::Node::NodeList::iterator j = tweet.begin(); j != tweet.end(); j++)
				{

					const ContentNode *i=dynamic_cast<const xmlpp::ContentNode*>(j.operator *());

					cout<<"i:\t"<<i->get_name()<<endl;
					if(i->get_name().compare("created_at")==0){
						tw->created_at.assign(i->get_content());
					}

					else if(i->get_name().compare("id")==0){
						tw->id.assign(i->get_content());
					}
					else if(i->get_name().compare("text")==0){
						tw->text.assign(i->get_content());
					}
					else if(i->get_name().compare("source")==0){
						tw->source.assign(i->get_content());
					}
					else if(i->get_name().compare("truncated")==0){
						tw->truncated.assign(i->get_content());
					}
					else if(i->get_name().compare("favorited")==0){
						tw->favorited.assign(i->get_content());
					}
					else if(i->get_name().compare("in_reply_to_status_id")==0){
						tw->in_reply_to_status_id.assign(i->get_content());
					}
					else if(i->get_name().compare("in_reply_to_user_id")==0){
						tw->in_reply_to_user_id.assign(i->get_content());
					}
					else if(i->get_name().compare("in_reply_to_screen_name")==0){
						tw->in_reply_to_screen_name.assign(i->get_content());
					}
					else if(i->get_name().compare("retweet_count")==0){
						tw->retweet_count.assign(i->get_content());
					}
					else if(i->get_name().compare("retweeted")==0){
						tw->retweeted.assign(i->get_content());
					}
					else if(i->get_name().compare("user")==0){

						xmlpp::Node::NodeList user=i->get_children("user");

						for(xmlpp::Node::NodeList::iterator x = user.begin(); x != user.end(); ++x){

							tw->setUser(dynamic_cast<const xmlpp::TextNode*>(x.operator *()));

						}

					}
					else if(i->get_name().compare("geo")==0){
						tw->geo.assign(i->get_content());
					}
					else if(i->get_name().compare("coordinates")==0){
						tw->coordinates.assign(i->get_content());
					}
					else if(i->get_name().compare("place")==0){
						tw->place.assign(i->get_content());
					}
					else if(i->get_name().compare("contributors")==0){
						tw->contributors.assign(i->get_content());
					}
				}
				timeline.push_back(*tw);

			}
		}
	}
	return timeline;
}

} /* namespace TwitCrusader */
