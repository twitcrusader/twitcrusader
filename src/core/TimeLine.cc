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

bool TimeLine::readTimeLineFromFile(ustring docname){

	DomParser parser;
	Tweet *tweet;

	parser.set_substitute_entities();
	parser.parse_file(docname);
	if(parser)
	{

		const xmlpp::Node* pNode = parser.get_document()->get_root_node();
		const Glib::ustring nodename = pNode->get_name();
		cout<<nodename<<endl;


		xmlpp::Node::NodeList status = pNode->get_children("status");
		for(xmlpp::Node::NodeList::iterator state = status.begin(); state != status.end(); ++state)
		{
			cout<<state.operator *()->get_name()<<endl;

			tweet=new Tweet();

			xmlpp::Node::NodeList values = state.operator *()->get_children();
			for(xmlpp::Node::NodeList::iterator iter = values.begin(); iter != values.end(); ++iter){


				const xmlpp::Element* nodeElement = dynamic_cast<const xmlpp::Element*>(*iter);

				Glib::ustring name;
				Glib::ustring content;


				if(nodeElement){

					name=nodeElement->get_name();
					if(nodeElement->get_child_text()!=NULL)content=nodeElement->get_child_text()->get_content();

					cout<<"\t"<<name.c_str()<<":\t";
					cout<<"\t"<<content.c_str()<<endl;

					if(name.compare("created_at")==0){
						tweet->created_at.assign(content);
					}
					else if(name.compare("id")==0){
						tweet->id.assign(content);

					}
					else if(name.compare("text")==0){
						tweet->text.assign(content);

					}else if(name.compare("source")==0){
						tweet->source.assign(content);

					}else if(name.compare("truncated")==0){
						tweet->truncated.assign(content);

					}else if(name.compare("favorited")==0){
						tweet->favorited.assign(content);

					}else if(name.compare("in_reply_to_status_id")==0){
						tweet->in_reply_to_status_id.assign(content);

					}else if(name.compare("in_reply_to_user_id")==0){
						tweet->in_reply_to_user_id.assign(content);

					}else if(name.compare("in_reply_to_screen_name")==0){
						tweet->in_reply_to_screen_name.assign(content);

					}else if(name.compare("retweet_count")==0){
						tweet->retweet_count.assign(content);

					}else if(name.compare("retweeted")==0){
						tweet->retweeted.assign(content);

					}else if(name.compare("user")==0){
						xmlpp::Node::NodeList users = iter.operator *()->get_children();

						for(xmlpp::Node::NodeList::iterator user = users.begin(); user != users.end(); ++user){
							const xmlpp::Element* userElement = dynamic_cast<const xmlpp::Element*>(*user);
							Glib::ustring username;
							Glib::ustring usercontent;


							if(userElement){

								username=userElement->get_name();
								if(userElement->get_child_text()!=NULL)usercontent=userElement->get_child_text()->get_content();
								cout<<"\t\t"<<username.c_str()<<":\t";
								cout<<"\t\t"<<usercontent.c_str()<<endl;


								if(username.compare("id")==0){
									tweet->user.id.assign(usercontent);
								}
								else if(username.compare("name")==0){
									tweet->user.name.assign(usercontent);

								}
								else if(username.compare("screen_name")==0){
									tweet->user.screen_name.assign(usercontent);

								}
								else if(username.compare("location")==0){
									tweet->user.location.assign(usercontent);

								}
								else if(username.compare("description")==0){
									tweet->user.description.assign(usercontent);

								}
								else if(username.compare("profile_image_url")==0){
									tweet->user.profile_image_url.assign(usercontent);

								}
								else if(username.compare("url")==0){
									tweet->user.url.assign(usercontent);

								}
								else if(username.compare("protectedtw")==0){
									tweet->user.protectedtw.assign(usercontent);

								}
								else if(username.compare("profile_background_color")==0){
									tweet->user.profile_background_color.assign(usercontent);

								}
								else if(username.compare("profile_text_color")==0){
									tweet->user.profile_text_color.assign(usercontent);

								}
								else if(username.compare("profile_link_color")==0){
									tweet->user.profile_link_color.assign(usercontent);

								}
								else if(username.compare("profile_sidebar_fill_color")==0){
									tweet->user.profile_sidebar_fill_color.assign(usercontent);

								}
								else if(username.compare("profile_sidebar_border_color")==0){
									tweet->user.profile_sidebar_border_color.assign(usercontent);

								}
								else if(username.compare("created_at")==0){
									tweet->user.created_at.assign(usercontent);

								}
								else if(username.compare("utc_offset")==0){
									tweet->user.utc_offset.assign(usercontent);

								}
								else if(username.compare("time_zone")==0){
									tweet->user.time_zone.assign(usercontent);

								}
								else if(username.compare("profile_background_image_url")==0){
									tweet->user.profile_background_image_url.assign(usercontent);

								}
								else if(username.compare("profile_background_tile")==0){
									tweet->user.profile_background_tile.assign(usercontent);

								}
								else if(username.compare("profile_use_background_image")==0){
									tweet->user.profile_use_background_image.assign(usercontent);

								}
								else if(username.compare("notifications")==0){
									tweet->user.notifications.assign(usercontent);

								}
								else if(username.compare("geo_enabled")==0){
									tweet->user.geo_enabled.assign(usercontent);

								}
								else if(username.compare("verified")==0){
									tweet->user.verified.assign(usercontent);

								}
								else if(username.compare("following")==0){
									tweet->user.following.assign(usercontent);

								}
								else if(username.compare("lang")==0){
									tweet->user.lang.assign(usercontent);

								}
								else if(username.compare("contributors_enabled")==0){
									tweet->user.contributors_enabled.assign(usercontent);

								}
								else if(username.compare("follow_request_sent")==0){
									tweet->user.follow_request_sent.assign(usercontent);

								}
								else if(username.compare("show_all_inline_media")==0){
									tweet->user.show_all_inline_media.assign(usercontent);

								}
								else if(username.compare("default_profile")==0){
									tweet->user.default_profile.assign(usercontent);

								}
								else if(username.compare("default_profile_image")==0){
									tweet->user.default_profile_image.assign(usercontent);

								}
								else if(username.compare("is_translator")==0){
									tweet->user.is_translator.assign(usercontent);

								}
								else if(username.compare("followers_count")==0){
									tweet->user.followers_count.assign(usercontent);

								}
								else if(username.compare("friends_count")==0){
									tweet->user.friends_count.assign(usercontent);

								}
								else if(username.compare("favourites_count")==0){
									tweet->user.favourites_count.assign(usercontent);

								}
								else if(username.compare("statuses_count")==0){
									tweet->user.statuses_count.assign(usercontent);

								}
								else if(username.compare("listed_count")==0){
									tweet->user.listed_count.assign(usercontent);

								}
							}
						}
					}
					else if(name.compare("geo")==0){
						tweet->geo.assign(content);

					}
					else if(name.compare("coordinates")==0){
						tweet->coordinates.assign(content);

					}
					else if(name.compare("place")==0){
						tweet->place.assign(content);

					}
					else if(name.compare("contributors")==0){
						tweet->contributors.assign(content);

					}

				}

			}
			timeline.push_back(*tweet);
		}
	}

	return 0;

}

bool TimeLine::readTimeLineFromString(ustring tmline)
{

	DomParser parser;
	Tweet *tweet;

	parser.set_substitute_entities();
	parser.parse_memory(tmline);
	if(parser)
	{

		const xmlpp::Node* pNode = parser.get_document()->get_root_node();
		const Glib::ustring nodename = pNode->get_name();
		cout<<nodename<<endl;


		xmlpp::Node::NodeList status = pNode->get_children("status");
		for(xmlpp::Node::NodeList::iterator state = status.begin(); state != status.end(); ++state)
		{
			cout<<state.operator *()->get_name()<<endl;

			tweet=new Tweet();

			xmlpp::Node::NodeList values = state.operator *()->get_children();
			for(xmlpp::Node::NodeList::iterator iter = values.begin(); iter != values.end(); ++iter){


				const xmlpp::Element* nodeElement = dynamic_cast<const xmlpp::Element*>(*iter);

				Glib::ustring name;
				Glib::ustring content;


				if(nodeElement){

					name=nodeElement->get_name();
					if(nodeElement->get_child_text()!=NULL)content=nodeElement->get_child_text()->get_content();

					cout<<"\t"<<name.c_str()<<":\t";
					cout<<"\t"<<content.c_str()<<endl;

					if(name.compare("created_at")==0){
						tweet->created_at.assign(content);
					}
					else if(name.compare("id")==0){
						tweet->id.assign(content);

					}
					else if(name.compare("text")==0){
						tweet->text.assign(content);

					}else if(name.compare("source")==0){
						tweet->source.assign(content);

					}else if(name.compare("truncated")==0){
						tweet->truncated.assign(content);

					}else if(name.compare("favorited")==0){
						tweet->favorited.assign(content);

					}else if(name.compare("in_reply_to_status_id")==0){
						tweet->in_reply_to_status_id.assign(content);

					}else if(name.compare("in_reply_to_user_id")==0){
						tweet->in_reply_to_user_id.assign(content);

					}else if(name.compare("in_reply_to_screen_name")==0){
						tweet->in_reply_to_screen_name.assign(content);

					}else if(name.compare("retweet_count")==0){
						tweet->retweet_count.assign(content);

					}else if(name.compare("retweeted")==0){
						tweet->retweeted.assign(content);

					}else if(name.compare("user")==0){
						xmlpp::Node::NodeList users = iter.operator *()->get_children();

						for(xmlpp::Node::NodeList::iterator user = users.begin(); user != users.end(); ++user){
							const xmlpp::Element* userElement = dynamic_cast<const xmlpp::Element*>(*user);
							Glib::ustring username;
							Glib::ustring usercontent;


							if(userElement){

								username=userElement->get_name();
								if(userElement->get_child_text()!=NULL)usercontent=userElement->get_child_text()->get_content();
								cout<<"\t\t"<<username.c_str()<<":\t";
								cout<<"\t\t"<<usercontent.c_str()<<endl;


								if(username.compare("id")==0){
									tweet->user.id.assign(usercontent);
								}
								else if(username.compare("name")==0){
									tweet->user.name.assign(usercontent);

								}
								else if(username.compare("screen_name")==0){
									tweet->user.screen_name.assign(usercontent);

								}
								else if(username.compare("location")==0){
									tweet->user.location.assign(usercontent);

								}
								else if(username.compare("description")==0){
									tweet->user.description.assign(usercontent);

								}
								else if(username.compare("profile_image_url")==0){
									tweet->user.profile_image_url.assign(usercontent);

								}
								else if(username.compare("url")==0){
									tweet->user.url.assign(usercontent);

								}
								else if(username.compare("protectedtw")==0){
									tweet->user.protectedtw.assign(usercontent);

								}
								else if(username.compare("profile_background_color")==0){
									tweet->user.profile_background_color.assign(usercontent);

								}
								else if(username.compare("profile_text_color")==0){
									tweet->user.profile_text_color.assign(usercontent);

								}
								else if(username.compare("profile_link_color")==0){
									tweet->user.profile_link_color.assign(usercontent);

								}
								else if(username.compare("profile_sidebar_fill_color")==0){
									tweet->user.profile_sidebar_fill_color.assign(usercontent);

								}
								else if(username.compare("profile_sidebar_border_color")==0){
									tweet->user.profile_sidebar_border_color.assign(usercontent);

								}
								else if(username.compare("created_at")==0){
									tweet->user.created_at.assign(usercontent);

								}
								else if(username.compare("utc_offset")==0){
									tweet->user.utc_offset.assign(usercontent);

								}
								else if(username.compare("time_zone")==0){
									tweet->user.time_zone.assign(usercontent);

								}
								else if(username.compare("profile_background_image_url")==0){
									tweet->user.profile_background_image_url.assign(usercontent);

								}
								else if(username.compare("profile_background_tile")==0){
									tweet->user.profile_background_tile.assign(usercontent);

								}
								else if(username.compare("profile_use_background_image")==0){
									tweet->user.profile_use_background_image.assign(usercontent);

								}
								else if(username.compare("notifications")==0){
									tweet->user.notifications.assign(usercontent);

								}
								else if(username.compare("geo_enabled")==0){
									tweet->user.geo_enabled.assign(usercontent);

								}
								else if(username.compare("verified")==0){
									tweet->user.verified.assign(usercontent);

								}
								else if(username.compare("following")==0){
									tweet->user.following.assign(usercontent);

								}
								else if(username.compare("lang")==0){
									tweet->user.lang.assign(usercontent);

								}
								else if(username.compare("contributors_enabled")==0){
									tweet->user.contributors_enabled.assign(usercontent);

								}
								else if(username.compare("follow_request_sent")==0){
									tweet->user.follow_request_sent.assign(usercontent);

								}
								else if(username.compare("show_all_inline_media")==0){
									tweet->user.show_all_inline_media.assign(usercontent);

								}
								else if(username.compare("default_profile")==0){
									tweet->user.default_profile.assign(usercontent);

								}
								else if(username.compare("default_profile_image")==0){
									tweet->user.default_profile_image.assign(usercontent);

								}
								else if(username.compare("is_translator")==0){
									tweet->user.is_translator.assign(usercontent);

								}
								else if(username.compare("followers_count")==0){
									tweet->user.followers_count.assign(usercontent);

								}
								else if(username.compare("friends_count")==0){
									tweet->user.friends_count.assign(usercontent);

								}
								else if(username.compare("favourites_count")==0){
									tweet->user.favourites_count.assign(usercontent);

								}
								else if(username.compare("statuses_count")==0){
									tweet->user.statuses_count.assign(usercontent);

								}
								else if(username.compare("listed_count")==0){
									tweet->user.listed_count.assign(usercontent);

								}
							}
						}
					}
					else if(name.compare("geo")==0){
						tweet->geo.assign(content);

					}
					else if(name.compare("coordinates")==0){
						tweet->coordinates.assign(content);

					}
					else if(name.compare("place")==0){
						tweet->place.assign(content);

					}
					else if(name.compare("contributors")==0){
						tweet->contributors.assign(content);

					}

				}

			}
			timeline.push_back(*tweet);
		}
	}

	return 0;

}
}

/* namespace TwitCrusader */
