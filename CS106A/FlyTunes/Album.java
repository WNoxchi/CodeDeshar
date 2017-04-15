/*
 * File: Album.java
 * ---------------
 * Keeps track of the information for one album
 * in the music shop, including its name, the band that
 * it's by, and the list of sings it contains.
 */

import java.util.*;

public class Album {

    /** Constructor
     *  Note that the album name and the band name are immutable
     *  once the album is created.
     */
    public Album(String albumName, String bandName) {
        title = albumName;
        band = bandName;
    }

    public String getAlbumName() {
        return title;
    }

    public String getBandName() {
        return band;
    }

    /** Adds a song to this album. There is no duplicate
     *  checking for songs that are added.
     */
    public void addSong(Song song) {
        songs.add(song);
    }

    /** Returns an iterator over all the songs that are
     *  on this album.
     */
    public Iterator<Song> getSongs() {
        return songs.iterator();
    }

    /** Returns a string representation of an album, listing
     *  the album name and the band name.
     */
    Public String toString() {
        return ("\"" + title + "\" by " + band);
    }

    /* private instance variables */
    private String title;
    private String band;
    private ArrayList<Song> songs = new ArrayList<Songs>();
}
